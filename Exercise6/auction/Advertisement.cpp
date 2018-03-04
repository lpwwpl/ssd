//: Advertisement.cpp linpeiwen
#include "Advertisement.h"

/*Default constructor 
Initializes the private data members to default values*/
Advertisement::Advertisement(void) : quantity(0), title(""), seller_email(""), body(""), start(), close() {

}
    
Advertisement::Advertisement(const Advertisement &a) {

	number = a.getNumber();
	quantity = a.getQuantity();
	title = a.getTitle();
	seller_email = a.getEmail();
	body = a.getBody();
	start = a.getStart();
	close = a.getClose();
}
    
Advertisement::Advertisement (string title, string seller_email, string body, 
					Date start, Date close, int quantity) : title(title), seller_email(seller_email), 
					body(body), start(start), close(close) {

}

	
void Advertisement::setStart (const Date &newstart) {

	start = newstart;
}
void Advertisement::setClose (const Date &newclose) {

	close = newclose;
}
void Advertisement::setTitle (string newtitle) {

	title = newtitle;
}
void Advertisement::setBody (string newbody) {

	body = newbody;
}
void Advertisement::setNumber (int newnumber) {

	number = newnumber;
}
void Advertisement::setEmail (string email) {

	seller_email = email;
}
void Advertisement::setQuantity (int newquantity) {

	quantity = newquantity;
}

Date Advertisement::getStart () const {

	return start;
}
Date Advertisement::getClose () const {

	return close;
}
string Advertisement::getTitle() const {

	return title;
}
string Advertisement::getBody() const {

	return body;
}
string Advertisement::getEmail() const {

	return seller_email;
}
int Advertisement::getNumber () const {

	return number;
}

int Advertisement::getQuantity() const {

	return quantity;
}

/*Compares Advertisement objects for equality. 
Two Advertisement objects are equal if their identification numbers are equal.*/
bool Advertisement::operator==(const Advertisement& newad) const {

	if (number == newad.getNumber()) {
	
		return true;
	}
	return false;
}

istream& operator>> (istream &stream,Advertisement& a) {
	string s;
	Date d;
	int i;
	stream >> s;
	a.setTitle(s);

	stream >> s;
	a.setEmail(s);

	stream >> i;
	a.setQuantity(i);

	stream >> d;
	a.setStart(d);
	stream >> d;
	a.setClose(d);
	stream >> s;
	a.setBody(s);

    return stream;
}

//Returns a reference to the priority queue of bids 
priority_queue<Bid>& Advertisement::getBids(void) {

	return bids;
}

/* 
 * Returns a vector of the winning bids in a "Dutch" style auction. "Dutch" style auctions are 
 * auctions that contain a quantity greater than one.
 */
vector<Bid> Advertisement::getTopDutchBids (void) const {

	Bid bid;
	vector<Bid> vector_bids;
	int quantity = this->quantity;	
	priority_queue<Bid> pb_queue;
	pb_queue = bids;

	//pb_queue is none then stop
	while(!pb_queue.empty()) {
	
		bid = pb_queue.top();
		
		vector_bids.push_back(bid);
		quantity = quantity - bid.getQuantity();	
	
		pb_queue.pop();

		if(quantity <= 0) {

			break;
		}
	}

	return vector_bids;
}
///:~