//: Client.cpp linpeiwen
#include "Client.h"

//Default constructor.Initializes the private data members to default values 
Client::Client(void):fname(""),lname(""),email(""),passwd(""){

}

//Copy constructor,Makes a copy of a Client object 
Client::Client(Client const &c) {
	fname = c.getFname();
	lname = c.getLname();
	email = c.getEmail();
	passwd = c.getPasswd();
}

//Four parameter constructor,accepts parameters to initialize the private data members 
Client::Client (string &fname, string &lname, string &email, string &passwd)
				:fname(fname),lname(lname),email(email),passwd(passwd) {
}

//The following 8 set or get methods are accessors and mutators povide access to the private data members 

void Client::setFname(const string& initFname) {
	fname = initFname;
}
void Client::setLname(const string& initLname) {
	lname = initLname;
}
void Client::setEmail(const string& initEmail) {
	email = initEmail;
}
void Client::setPasswd(const string& initPasswd) {
	passwd = initPasswd;
}

string Client::getFname () const {
	return fname;
}
string Client::getLname () const {
	return lname;
}
string Client::getEmail () const {
	return email;
}
string Client::getPasswd () const {
	return passwd;
}

//Returns true if the invoking object's password matches the password given in the parameter, false if otherwise.
bool Client::verifyPasswd(string passwd) {
	if(this->passwd == passwd) {
		return true;
	} else {
		return false;
	}
}

/*
 * This method reads a Client object from an input stream. The advertisement should be input the following data members 
 * of the class in the following form. 
 * firstname \n lastname \n email \n password \n
 *
 */
istream &operator>>(istream &stream, Client &c) {
	string fname,lname,email,passwd;
	//Use the c++ istream to set the attributes of Client.
	stream >> fname >> lname >> email >> passwd;
	c.setEmail(email);
	c.setFname(fname);
	c.setLname(lname);
	c.setPasswd(passwd);
	return stream;
}
///:~