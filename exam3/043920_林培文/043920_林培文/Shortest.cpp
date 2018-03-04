//:Shortest.cpp linpeiwen
#pragma warning(disable:4786)

#include "Shortest.h"
#include "main.h"

using namespace std;

// Models a shortest path calculation between two registered users.
Shortest::Shortest(const string &start_email) {

    // TODO: Finish implementation
	
	//if the start_email is not exited in users,stop(return).
	if(users[start_email] == NULL) {
		
		return;
	}
	
	// Constructing an adjacency list representation of the graph of bids and postings 
	// between users. This involves populating the private variable table.
	for(Group::iterator user_it = users.begin();user_it != users.end();user_it++) {
		
		ShortestEntry ste;		

		ste.email = (*user_it)->getEmail();
		ste.hop_count = END_SHORTEST_ITERATOR;
		ste.relationship = NONE;
		ste.via = "";

		// Populate the bids set to contain the email addresses whose auctions this 
		// user has bid on. 
		for(vector<int>::iterator user_bids_it = (*user_it)->beginBids();user_bids_it != (*user_it)->endBids();user_bids_it++) {
			
			vector<Bid> topDutchBids = advertisements[(*user_bids_it)]->getTopDutchBids();

			while(!topDutchBids.empty()) {
				
				string str = topDutchBids.back().getEmail();
				
				if(str == ste.email) {
				
					ste.bids.insert(advertisements[*user_bids_it]->getEmail());
				}

				topDutchBids.pop_back();
			}
		}
		
		// Populate the offerings set to contain the email addresses of the users who 
		// have placed the highest bids for each of this user's auctions{using getTopDutchBids()}. 
		for(vector<int>::iterator user_offerings_it = (*user_it)->beginOfferings();user_offerings_it != (*user_it)->endOfferings();user_offerings_it++) {
		
			vector<Bid>	topDutchBids = advertisements[*user_offerings_it]->getTopDutchBids();
			
			if(!topDutchBids.empty()) {	
			
				for(vector<Bid>::iterator it = topDutchBids.begin();it != topDutchBids.end();it++) {
			
					ste.offerings.insert(it->getEmail());
				}
			}
		}

		// table of map<string, ShortestEntry> type maps a user's email address to
		// an instance of type ShortestEntry.for loop to map all the users' email address.
		table[(*user_it)->getEmail()] = ste;
	}

	// Find the starting point
	map<string,ShortestEntry>::iterator table_it = table.find(start_email);
	
	// Stop if the starting point is not mapped.
	if(table_it == table.end()) {
	
		return;
	}

	// Update the the starting point's table map.
	table[start_email].via = start_email;
	table[start_email].hop_count = 0;
	table[start_email].relationship = START;

	// Push the starting point into recently_known
	recently_known.push(table[start_email]);


	int usernode = 0;
	
	// Start loops to calculation between two registered users. 
	for(;usernode < table.size();usernode++) {
	
		// The algorithm terminates when the recently_known queue is empty.
		if(recently_known.empty()) {
			
			break;
		}

		// Grab the edge from the recently queue's node.process the edge and remove it from the queue
		ShortestEntry se = recently_known.front();
		recently_known.pop();
		
		// Update the table to find those associated by bids and 
		// add those found to the recently_known.
		for(set<string>::iterator bids_it = (se).bids.begin();bids_it != (se).bids.end();bids_it++) {
			
			if(table[(*bids_it)].relationship == NONE) {
				
				table[(*bids_it)].hop_count = table[(*bids_it)].hop_count + 1;
				table[(*bids_it)].via = se.email;
				table[(*bids_it)].relationship = BUYER;
				recently_known.push(table[(*bids_it)]);
			}			
		}
		
		// Update the table to find those associated by offerings and 
		// add those found to the recently_known.
		for(set<string>::iterator offerings_it = (se).offerings.begin();offerings_it != (se).offerings.end();offerings_it++) {

			if(table[(*offerings_it)].relationship == NONE) {
				
				table[(*offerings_it)].hop_count = table[(*offerings_it)].hop_count + 1;
				table[(*offerings_it)].via = se.email;
				table[(*offerings_it)].relationship = SELLER;
				recently_known.push(table[(*offerings_it)]);
			}
		}
	}
}


vector<string> Shortest::get_path(const string &destination_userid) {

  string current_userid = destination_userid;
  vector<string> events;
  bool relationship = true;

  while (true) {

        map<string,ShortestEntry>::iterator posn = 
           table.find(current_userid);

        // Stop if the current user is unknown
        if (posn == table.end()) {
          relationship = false;
          break;
        }

        // Stop if the current user is unreachable
        if (NONE == posn->second.relationship) {
          relationship = false;
          break;
        }

        // We have a valid, reachable user, so save the action
        if (BUYER == posn->second.relationship) {
          string description;

          description = posn->second.via + " bid on an item offered by " 
                  + posn->second.email;
          events.push_back(description);
          cout << description << endl;
        }
        else if (SELLER == posn->second.relationship) {
          string description;

          description = posn->second.via 
                  + " is offering an item with a high bid from " 
                  + posn->second.email;
          events.push_back(description);
          cout << description << endl;
        }


        // Stop if this was the first one -- no more actions
        if (START == posn->second.relationship) {
          break;
        }

        // Set up for the next action
        current_userid = posn->second.via;
      
  }

  if (0 == events.size() || !relationship) {
     events.push_back ("No relationship found between specified users.");
  }

  return events;

}
///:~

