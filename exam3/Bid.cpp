#include <cstdlib>

#include "Bid.h"

using namespace std;

Bid::Bid(void) : 
	email(""), amount(-1.0),
	quantity(1), date() {}	


Bid::Bid(const Bid &b) : 
	email(b.email), amount(b.amount), 
	quantity(b.quantity), date(b.date) {}

Bid::Bid (string email, float amount, int quantity, Date date) :
	email(email), amount(amount),
	quantity(quantity), date(date) {}
  

void Bid::setEmail(const string& email) {
	this->email = email;
}

void Bid::setDate(const Date& date) {
	this->date = date;
}

void Bid::setAmount(const float& amount) {
	this->amount = amount;
}

void Bid::setQuantity(const int& quantity) {
	this->quantity = quantity;
}

float Bid::getAmount() const {
	return amount;
}

string Bid::getEmail() const{
	return email;
}

Date Bid::getDate() const {
	return date;
}

int Bid::getQuantity() const {
	return quantity;
}	

bool Bid::operator< (const Bid& rhs) const {
  return (this->getAmount() < rhs.getAmount());
}

bool Bid::operator== (const Bid& rhs) const {
  return (this->getAmount() == rhs.getAmount());
}

istream &operator>>(istream &stream, Bid &b) {

	char line[80];
	string name;

	stream.getline(line, 80);

	b.setEmail(line);

	stream.getline(line, 80);
	b.setAmount(atof(line));

	stream.getline(line, 80);
	b.setQuantity(atoi(line));

	Date d;
	stream >> d;
	b.setDate(d);

	return stream;
}


