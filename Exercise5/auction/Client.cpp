#include "Client.h"

//istream &operator>>(istream &stream, Client &c);

    /*string fname;
    string lname;
    string email;
    string passwd;*/
  
Client::Client(void) : fname(), lname(), email(), passwd(){

}
Client::Client(Client const &c) {

	fname = c.getFname();
	lname = c.getLname();
	email = c.getEmail();
	passwd = c.getPasswd();
}
Client::Client (string &fname, string &lname, string &email, string &passwd) : 
				fname(fname), lname(lname), email(email), passwd(passwd) {

}

void Client::setFname(const string& newfname) {
	
	fname = newfname;
}

void Client::setLname(const string& newlname) {

	lname = newlname;
}

void Client::setEmail(const string& newemail) {

	email = newemail;
}

void Client::setPasswd(const string& newpasswd) {

	passwd = newpasswd;
}

string Client::getFname () const {

	return fname;
}
string Client::getLname () const {

	cout << "getlname" <<endl;
	return lname;
}

string Client::getEmail () const {

	return email;
}

string Client::getPasswd () const {

	return passwd;
}

bool Client::verifyPasswd(string newpasswd) {

	if (passwd == newpasswd) {
	
		return true;
	}
	return false;
}

/*This method reads a Client object from an input stream. 
The advertisement should be input the following data members of the class in the following form. 
firstname \n lastname \n email \n password \n */
istream &operator>>(istream &stream, Client &c) {

	string fname, lname, email, passwd;

	stream >> fname >> lname >> email >> passwd;
	c.setFname(fname);
	c.setLname(lname);
	c.setEmail(email);
	c.setPasswd(passwd);
	return stream;
}

//Returns a begin iterator for the offerings vector 
vector<int>::iterator Client::beginOfferings() {

	return offerings.begin();
}

//Returns an end iterator for the offerings vector 
vector<int>::iterator Client::endOfferings() {

	return offerings.end();
}

//Returns a begin iterator for the bids vector 
vector<int>::iterator Client::beginBids() {

	return bids.begin();
}

//Returns an end iterator for the bids vector 
vector<int>::iterator Client::endBids() {

	return bids.end();
}

//Adds an advertisement number to the bids vector 
void Client::addBid (int item) {

	bids.push_back(item);
}
 
//Adds an advertisement number to the offerings vector 
void Client::addOffering (int item) {

	offerings.push_back(item);
}