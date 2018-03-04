//: displayBidHistory.cpp linpeiwen
#include "bidhistory.h"
#include "Client.h"
#include "Group.h"
#include "Advertisement.h"
#include "Listing.h"
#include "main.h"

void displayBidHistory(ostringstream &oss, Advertisement* ad) {	
	
	//Create client object.
	Client* seller = NULL;
	seller = users[ad->getEmail()];
	
	//output the information of the advertisement.
	oss << "Posted By: <A HREF=mailto:" << ad->getEmail() << ">";
	oss << seller->getLname() << ", " << seller->getFname() << "</a><br>" << endl;
	oss << "Posted: " << ad->getStart() << "<br>" << endl;
	oss << "Closes: " << ad->getClose() << "<br>" << endl;
	oss << "Quantity: " << ad->getQuantity() << "<br>" << endl;
	oss << "Number of bids: " << ad->getBids().size() << "<br>" << endl;
	oss << "<br>" << endl;

	//quantity is the ad's quantity.
	int quantity = ad->getQuantity();

	//generate the html.
	if (ad->getBids().size() == 0) {

		oss << "There are no bids for this item" << endl;
		
	} else if (quantity == 1) {
    
	    Bid bid = ad->getBids().top();
        oss << ad->getBids().size() << " bids<br>" << endl;
        oss << "High bid is $" << bid.getAmount() << "("  
            << bid.getEmail() << ")<br>" << endl;
	
	} else { 

		//store the winning bids.
		vector<Bid> bids = ad->getTopDutchBids();
		int bid_number = 0;

		oss << "Highest winning bid is $" << bids.front().getAmount() << "<br>" << endl;
		oss << "Lowest winning bid is $" << bids.back().getAmount() << "<br><br>" << endl;	

		oss << "High bidders are:<br>" << endl;
		
		int i = 0;
		vector<Bid>::iterator bids_it;
		
		//iterate through the bids to output the 
		for(bids_it = bids.begin(),i = 1;bids_it != bids.end();bids_it++,i++) {
		
		   //use bid_number variable to keep track the available quantity of the ad.
		   bid_number = (bids_it->getQuantity() <= quantity ? bids_it->getQuantity() : quantity);
			
		   oss << i << ". " << bids_it->getEmail() <<" bid $" << bids_it->getAmount() << " per item for each of " << bids_it->getQuantity() 
				<< " items and is the higher bidder for " <<  bid_number << " of them." << "<br><br>" << endl;

			quantity = quantity - bids_it->getQuantity();
		
			//if quantity <= 0 indicate that the quantity of ad are all be bided,then break the for loop. 
			if(quantity <= 0) {
		
				break;
			}
		}

		oss << "<br>" << endl;

		// output the remain availabe quantity of the ad.
		if(quantity <= 0) {
		
			oss << "0 items remain unbid.";
		} else {
		
			oss << quantity << " items remain unbid.";
		}
	}
}
///:~