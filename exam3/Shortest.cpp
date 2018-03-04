#pragma warning(disable:4786)

#include "Shortest.h"
#include "main.h"

using namespace std;

Shortest::Shortest(const string &start_email) {

    // TODO: Finish implementation		
	if(users[start_email] == NULL) {
	
		return;
	}

	for(vector<Client*>::iterator client_it = users.begin();client_it != users.end();client_it++) {

		ShortestEntry se;
		se.hop_count = END_SHORTEST_ITERATOR;
		se.via = "";
		se.relationship = NONE;
		se.email = (*client_it)->getEmail();
		
		for(vector<int>::iterator bids_it = (*client_it)->beginBids();bids_it != (*client_it)->endBids();bids_it++) {
			
			vector<Bid>	topDutchBids = advertisements[*bids_it]->getTopDutchBids();
			
			if(!topDutchBids.empty()) { 
			
				for(vector<Bid>::iterator it = topDutchBids.begin();it != topDutchBids.end();it++) {
			
					string email = it->getEmail();
				
					if(se.email == email) {

						se.bids.insert(advertisements[*bids_it]->getEmail());
					}
				}
			}
		}

		for(vector<int>::iterator offerings_it = (*client_it)->beginOfferings();offerings_it != (*client_it)->endOfferings();offerings_it++) {
			
			vector<Bid>	topDutchBids = advertisements[*offerings_it]->getTopDutchBids();
			
			if(!topDutchBids.empty()) {	
			
				for(vector<Bid>::iterator it = topDutchBids.begin();it != topDutchBids.end();it++) {
			
					se.offerings.insert(it->getEmail());
				}
			}
		}

		table[(*client_it)->getEmail()] = se;
	}
	
	table[start_email].hop_count = 0;
	table[start_email].relationship = START;
	recently_known.push(table[start_email]);	

	int node = 0;

	for(;node < table.size();node++) {
	
		if(recently_known.empty()) {

			break;
		}

		Client* client = users[recently_known.front().email];
		recently_known.pop();	
		
		for(set<string>::iterator bids_it = table[client->getEmail()].bids.begin();bids_it != table[client->getEmail()].bids.end();bids_it++) {
			
			Client* bids_client = users[*bids_it];
			
			if(table[bids_client->getEmail()].hop_count < 0) {
			
				table[bids_client->getEmail()].relationship = BUYER;
				table[bids_client->getEmail()].via = client->getEmail();
				table[bids_client->getEmail()].hop_count = table[client->getEmail()].hop_count + 1;
				recently_known.push(table[bids_client->getEmail()]);
			}
		}	

		for(set<string>::iterator offerings_it = table[client->getEmail()].offerings.begin();offerings_it != table[client->getEmail()].offerings.end();offerings_it++) {
		
			Client* offerings_client = users[*offerings_it];
		
			if(table[offerings_client->getEmail()].hop_count < 0) {
			
				table[offerings_client->getEmail()].relationship = SELLER;
				table[offerings_client->getEmail()].via = client->getEmail();
				table[offerings_client->getEmail()].hop_count = table[client->getEmail()].hop_count + 1;
				recently_known.push(table[offerings_client->getEmail()]);
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

