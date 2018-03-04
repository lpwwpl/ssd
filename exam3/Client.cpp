#include <string>
#include <cstring>
#include <vector>

#include "Client.h"

using namespace std;

Client::Client(void) : 
	fname(""), lname(""), 
	email(""), passwd(""),
	bids(), offerings()
	{}
  
Client::Client(Client const &c) :
	fname(c.fname), lname(c.lname), email(c.email),
	passwd(c.passwd), offerings(c.offerings),
	bids(c.bids) {}

Client::Client (string &fname, string &lname, string &email, string &passwd) :
	fname(fname), lname(lname), 
	email(email), passwd(passwd),
	bids(), offerings()
	{}


string Client::getFname() const {
	return fname;
}


string Client::getLname() const {
	return lname;
}


string Client::getEmail() const {
	return email;
}

string Client::getPasswd() const {
	return passwd;
}

void Client::setFname(const string& fname) {
	this->fname = fname;
}

void Client::setLname(const string& lname) {
	this->lname = lname;
}

void Client::setEmail(const string& email) {
	this->email = email;
}

void Client::setPasswd(const string& passwd) {
	this->passwd = passwd;
}


vector<int>::iterator Client::beginOfferings() {
	return offerings.begin();
}


vector<int>::iterator Client::endOfferings() {
	return offerings.end();
}


vector<int>::iterator Client::beginBids() {
	return bids.begin();
}


vector<int>::iterator Client::endBids() {
	return bids.end();
}


bool Client::verifyPasswd(string passwd) {
  if (passwd == this->passwd) 
    return true;

  return false;
}


void Client::addBid(int auction) {
  bids.push_back (auction);
}


void Client::addOffering(int auction) {
  offerings.push_back (auction);
}

istream &operator>>(istream &stream, Client &c) {

	char line[80];
	string name;

	stream.getline(line, 80);
	c.setFname(line);

	stream.getline(line, 80);
	c.setLname(line);

	stream.getline(line, 80);
	c.setEmail(line);

	stream.getline(line, 80);
	c.setPasswd(line);

	return stream;
}



