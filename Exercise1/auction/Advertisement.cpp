//: Advertisement.cpp linpeiwen
#include "Advertisement.h"
#include "Date.h"
using namespace std;

//Initializes the private data members to default values.
Advertisement::Advertisement():number(0),quantity(0),title(""),seller_email(""),body(""),start(Date()),close(Date()) {

}

//Makes a copy of a Advertisement object.
Advertisement::Advertisement(const Advertisement &a) {
	number = a.getNumber();
	quantity = a.getQuantity();
	title = a.getTitle();
	seller_email = a.getEmail();
	body = a.getBody();
	start = a.getStart();
	close = a.getClose();
}

//Accepts parameters to initialize the private data members.
Advertisement::Advertisement (string title, string seller_email, string body, 
							  Date start, Date close, int quantity) {
	this->title = title;
	this->seller_email = seller_email;
	this->body = body;
	this->start = start;
	this->close = close;
	this->quantity = quantity;

}

//The following set and get methods are accessors and mutators provide access to the private data members. 
void Advertisement::setStart (const Date &start) {
	this->start = start;
}
void Advertisement::setClose (const Date &close) {
	this->close = close;
}
void Advertisement::setTitle (string title) {
	this->title = title;
}
void Advertisement::setBody (string body) {
	this->body = body;
}
void Advertisement::setNumber (int number) {
	this->number = number;  
}
void Advertisement::setEmail (string email) {
	seller_email = email;
}
void Advertisement::setQuantity (int quantity) {
	this->quantity = quantity;
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

//Compares Advertisement objects for equality. Two Advertisement objects are equal if their identification numbers are equal.    
bool Advertisement::operator==(const Advertisement& ad) const {
	if(number == ad.getNumber()) {
		return true;
	} else {
		return false;
	} 
}

/*
 * This method reads an Advertisement object from an input stream. The advertisement should be input the following 
 *  data members of the class in the following form. 
 *  title \n email \n quantity \n start-date \n close-date \n body \n
 *
 */
istream &operator>>(istream &stream, Advertisement &a) {
	string title,email,body;
	int quantity;
	Date start_date,close_date;
	//Use the c++ istream to set the attributes of advertisement.
	stream >>title>>email>>quantity>>start_date>>close_date>>body;
	a.setStart(start_date);
	a.setClose(close_date);
	a.setTitle(title);
	a.setEmail(email);
	a.setQuantity(quantity);
	a.setBody(body);
	return stream;
}
