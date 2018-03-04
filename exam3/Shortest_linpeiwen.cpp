#pragma warning(disable:4786)

#include "Shortest.h"
#include "main.h"
#include "fstream"

using namespace std;

Shortest::Shortest(const string &start_email) {
	typedef map<string,ShortestEntry>::value_type mapValue;
	Group::iterator it1 = users.begin();
	Group::iterator it2 = users.end();
	vector<int>::iterator it3,it4;
	for(;it1 != it2;it1++){
		Client *pClient = *it1;
		string emailFrom = (*it1)->getEmail();
		if(!table.count(emailFrom))
			table.insert(mapValue(emailFrom,ShortestEntry()));

		//查看用户的第一个bid，若这个bid是对应产品的最高价，也即用户买了这个产品，
		//我们即可以把发布对应产品的用户，和当前用户关联起来
		for(it3 = pClient->beginBids();it3 != pClient->endBids();it3++){
			priority_queue<Bid>& bidOfAdvertisement = advertisements[*it3]->getBids();
			if(!bidOfAdvertisement.empty()){
				string email = bidOfAdvertisement.top().getEmail();
				if(email == emailFrom)
					table[emailFrom].bids.insert(advertisements[*it3]->getEmail());
			}
		}
		//查看用户发布的每一个产品，把购买该产品的用户关联进来
		for(it4 = pClient->beginOfferings();it4 !=pClient->endOfferings();it4++){
			priority_queue<Bid>& bidOfOfferings = advertisements[*it4]->getBids();
			if(!bidOfOfferings.empty()){
				string email = bidOfOfferings.top().getEmail();
				table[emailFrom].offerings.insert(email);
			}
		}
		table[emailFrom].via="";
		table[emailFrom].hop_count=-1;
		table[emailFrom].relationship=NONE;
		table[emailFrom].email = emailFrom;
	}
    // 查找最短路径
	
	table[start_email].relationship = START;
	table[start_email].via = start_email;
	table[start_email].hop_count = 0;
	ShortestEntry st = table[start_email];
	recently_known.push(st);

	unsigned int numOfClients = 0;
	cout<<"TableSize: "<<table.size()<<endl;
	for( ; numOfClients < table.size(); numOfClients ++){
		if(recently_known.empty())
			return;
		st = recently_known.front();
		recently_known.pop();
		set<string>::iterator it1Bids = st.bids.begin();
		set<string>::iterator it2Bids = st.bids.end();
		set<string>::iterator it3Offerings = st.offerings.begin();
		set<string>::iterator it4Offerings = st.offerings.end();
		for(;it1Bids != it2Bids;it1Bids++){
			if(table[*it1Bids].hop_count < 0){
				table[*it1Bids].relationship = BUYER;
				table[*it1Bids].via = st.email;
				table[*it1Bids].hop_count = st.hop_count + 1;
				recently_known.push(table[*it1Bids]);
			}
		}
		for(;it3Offerings != it4Offerings;it3Offerings++){
			if(table[*it3Offerings].hop_count < 0){
				table[*it3Offerings].relationship = SELLER;
				table[*it3Offerings].via = st.email;
				table[*it3Offerings].hop_count = st.hop_count + 1;
				recently_known.push(table[*it3Offerings]);
				cout<<table[*it3Offerings].email<<" is pushed !"<<endl;
			}
		}			
	}

}
/*void Shortest::displayMap(string file_name)
{
	ofstream ofs(file_name.c_str());
	map<string,ShortestEntry>::iterator it1 = table.begin();
	map<string,ShortestEntry>::iterator it2 = table.end();
	for(;it1 != it2;it1++){
		ofs<<(*it1).first<<" relation : "<<(*it1).second.relationship<<" via: "<<(*it1).second.via<<" hopcount: "<<(*it1).second.hop_count<<endl;;
		set<string>::iterator it3 = (*it1).second.bids.begin();
		set<string>::iterator it4 = (*it1).second.bids.end();
		ofs<<"\t\tisbuyerfor(bids) : ";
		for(;it3 != it4;it3++)
			ofs<<(*it3)<<" ";
		ofs<<endl;
		it3 = (*it1).second.offerings.begin();
		it4 = (*it1).second.offerings.end();
		ofs<<"\t\tissellerfor(offerings) : ";
		for(;it3 != it4;it3++)
			ofs<<(*it3)<<" ";
		ofs<<endl<<endl;
	}
	ofs.close();

}*/
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

