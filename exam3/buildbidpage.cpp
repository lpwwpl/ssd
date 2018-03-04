#include <sstream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <signal.h>
#include <cstdio>

#include "main.h"
#include "buildpage.h"
#include "buildbidpage.h"
#include "Client.h"
#include "Advertisement.h"
#include "Listing.h"
#include "Group.h"

using namespace std;

void buildbidpage (ostringstream &oss, int port, int number) {

	in_addr ip;
	ip = getIP();

	displayPageHeader(oss);

	Advertisement *ad = NULL;
	ad = advertisements[number];
   
	oss << "<table border=0 width=100%>" << endl;
	oss << "<tr><td valign=top width=50%>" << endl;
	oss << "<b>" << ad->getTitle() << "</b><br>" << endl;
	displayBidHistory(oss, ad);

	oss << "<td valign=top>" << endl;
	displayBidForm(oss, ip, port, number);
	oss << "</tr></table>" << endl;
 
	oss << "</body>" << endl;
	oss << "</html>" << endl;
}

void displayBidHistory(ostringstream &oss, Advertisement* ad) {

	Client* seller = NULL;
	seller = users[ad->getEmail()];

	oss << "Posted by: <A HREF=mailto:" << ad->getEmail() << ">";  
	oss << seller->getLname() << ", " << seller->getFname() << "</a><br>" << endl;
	oss << "Posted: " << ad->getStart() << "<br>" << endl;
	oss << "Closes: " << ad->getClose() << "<br>" << endl;
	oss << "Quantity: "	<< ad->getQuantity() << "<br>" << endl;

	if (0 == ad->getBids().size()) {
		oss << "There are no bids for this item" << endl;
	}
	else if (1 == ad->getQuantity()) {
    
	  Bid b = ad->getBids().top();
      oss << ad->getBids().size() << " bids<br>" << endl;
      oss << "High bid is $" << b.getAmount() << "("  
          << b.getEmail() << ")<br>" << endl;
	} 
	else if (1 < ad->getQuantity()) {

      vector<Bid> topBids = ad->getTopDutchBids();

      float lowestAmount = topBids[topBids.size()-1].getAmount();
      float highestAmount = topBids[0].getAmount();

      oss << "Highest winning bid is $" << highestAmount << "<BR>" << endl;
      oss << "Lowest winning bid is $" << lowestAmount << "<BR>" << endl;
      oss << "<P>" << endl;
      oss << "High bidders are: " << endl;

      oss << "<OL>" << endl;

      int claimedQty = 0;
      int unClaimedQty = ad->getQuantity();
      for (int index=0; index < topBids.size(); index++) {
        int bidderTaking = (topBids[index].getQuantity() <= unClaimedQty ?
                            topBids[index].getQuantity() :
                            unClaimedQty);

        claimedQty += bidderTaking;
        unClaimedQty -= bidderTaking;

        oss << "<LI>" << topBids[index].getEmail() << " bid $" 
            << topBids[index].getAmount() << " per item for each of " 
            << topBids[index].getQuantity() 
            << " items and is the higher bidder for " << bidderTaking 
            << " of them.</LI>" << endl;
      }
      oss << "</OL>" << endl;

    oss << "<br>" << endl;
    oss << unClaimedQty << " items remain unbid." << endl;
	}
}

void displayBidForm(ostringstream &oss, struct in_addr ip, int port, int number) {

	Advertisement *ad = NULL;
	ad = advertisements[number];

	oss << "<FORM ACTION=" << CLASSIFIED_CGI << " METHOD=POST>" << endl;
	oss << "<INPUT NAME=PORT TYPE=hidden VALUE=" << port << ">" << endl;
	oss << "<INPUT NAME=IP TYPE=hidden VALUE=" << inet_ntoa(ip) << ">" << endl;
	oss << "<INPUT NAME=email TYPE=hidden VALUE=" << active_user << ">" << endl;
	oss << "<INPUT NAME=number TYPE=hidden VALUE=" << number << ">" << endl;

	oss << "<b><center>Place Bid</center></b><br>" << endl;
	oss << "<table border=0 width=100%>" << endl;
	oss << "<tr><td align=right>Bid amount:" << endl;

	float high_bid = 0;
	if (ad->getBids().size() > 0) {
		high_bid = ad->getBids().top().getAmount();
	}
	oss << "<td><INPUT NAME=amount TYPE=text SIZE=5 VALUE="
		<< high_bid + 1 << "></tr>" << endl;
 
	oss << "<tr><td align=right>Quantity:" << endl;
	if  (ad->getQuantity() > 1) {
		oss << "<td><INPUT NAME=quantity SIZE=5 TYPE=text VALUE=1></tr>" << endl;
	}
	else {
		oss << "<td><INPUT NAME=quantity TYPE=hidden VALUE=1>1</tr>" << endl;
	}

	oss << "<tr><td align=center colspan=2>" << endl;
	oss << "<INPUT NAME=COMMAND TYPE=submit VALUE=\"Submit bid\">" << endl;
	oss << "</FORM>" << "</tr></table>" << endl;
}
