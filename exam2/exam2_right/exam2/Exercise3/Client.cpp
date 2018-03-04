#include <iostream>
#include "Client.h"

using namespace std;

//Default constructor 
Client::Client():fname(""), lname(""), email(""), passwd(""){}

//Four parameter constructor
Client::Client (string &f, string &ln, string &em, string &p):fname(f),lname(ln),email(em),passwd(p){}

//Makes a copy of a Client object 
Client::Client(Client const &c){
	fname=c.fname ;
    lname=c.lname ;
    email=c.email ;
    passwd=c.passwd ;
}

//Accessors and mutators 
//Provide access to the private data members 
void Client::setFname(const string &f){ fname=f;}
void Client::setLname(const string &l){lname=l;}
void Client::setEmail(const string &e){email=e;}
void Client::setPasswd(const string &p){passwd=p;}

string Client::getFname () const{return fname;}
string Client::getLname () const{return lname;}
string Client::getEmail () const{return email;}
string Client::getPasswd () const{return passwd;}

//virtual bool verifyPasswd(string passwd)
//Returns true if the invoking object's password matches the password given in the parameter, false if otherwise.
bool Client::verifyPasswd(string pd){
	if(passwd==pd)
		return 1;
	else
		return 0;
}

//Reads a Client object from an input stream in the following form "firstname \n lastname \n email \n password \n" 
istream &operator>>(istream &stream, Client &c){
	//char h;
       string f,l,e,p;
    
	stream>>f;
	c.setFname(f);
	//stream>>h;
	
	stream>>l;
	c.setLname(l);
	//stream>>h;
	
	stream>>e;
	c.setEmail(e);
	//stream>>h;
	
	stream>>p;
	c.setPasswd(p);
	//stream>>h;
	
	return stream;
}
