//:Bid.h linpeiwen
#include "Bid.h"

/*
* Default constructor 
* Initializes the private data members to default values.
*/
Bid::Bid() : email(""), amount(0), quantity(0), date() {

}

/*
* Four parameter constructor 
* Accepts parameters for email address, bid amount, quantity, and date.
*/
Bid::Bid (string email, float amount, int quantity, Date date) 
: email(email), amount(amount), quantity(quantity), date(date) {

}

/*
* Copy constructor 
* Makes a copy of a Bid object 
*/
Bid::Bid(const Bid &b) {

	email = b.getEmail();
	amount = b.getAmount();
	quantity = b.getQuantity();
	date = b.getDate();
}

/*
* Accessors and mutators 
* Provides access to the data members of the class 
*/
string Bid::getEmail() const {

	return email;
}

float Bid::getAmount() const {

	return amount;
}

Date Bid::getDate() const {

	return date;
}

int Bid::getQuantity() const {

	return quantity;
}

void Bid::setEmail(const string& new_email) {

	email = new_email;
}

void Bid::setAmount(const float& new_amount) {

	amount = new_amount;
}

void Bid::setQuantity(const int& new_quantity) {

	quantity = new_quantity;
}

void Bid::setDate(const Date& new_date) {

	date = new_date;
}

/*
 * Reads a Bid object from an input stream. The bid should input the following data members of the class in the form 
 * email \n amount \n quantity \n date \n
 */
istream &operator>>(istream &stream, Bid &b) {

	string s;
	float f;
	int i;
	Date d;

	stream >> s;
	b.setEmail(s);

	stream >> f;
	b.setAmount(f);

	stream >> i;
	b.setQuantity(i);

	stream >> d;
	b.setDate(d);

	return stream;
}

/*
* Compares the invoking Bid object against the parameter to determine if the invoking 
* Bid object is less than the parameter Bid. Use the dollar amount to compare two bids.
*/
bool Bid::operator< (const Bid &rhs) const {
	
	if(amount < rhs.getAmount()) {
	
		return true;
	}
	return false;
}

/* 
* Compares the invoking Bid object and the parameter Bid object for equality. 
* Bids are considered equal if their amounts are equal.
*/
bool Bid::operator == (const Bid &rhs) const {

	if(amount == rhs.getAmount()) {
	
		return true;
	}
	return false;
}
///:~