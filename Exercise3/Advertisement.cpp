#include <iostream>
#include "Advertisement.h"

using namespace std;
istream &operator>>(istream &stream, Advertisement &a);
//Default constructor 
Advertisement::Advertisement():number(0),quantity(0),title(""),seller_email(""),body(""),
                               start(),close(){}

//Six parameter constructor 
//Initializes the Advertisement with meaningful data
Advertisement::Advertisement (string t, string s_email, string b, Date s, Date c, int q)
              :title(t),seller_email(s_email),body(b),start(s),close(c),quantity(q),number(0){}
  
//copyconstructor
Advertisement::Advertisement(const Advertisement &a){
	number=a.number ;
	quantity=a.quantity ;
	title=a.title ;
	seller_email=a.seller_email ;
	body=a.body ;
	start=a.start ;
	close=a.close ;
}

//Accessors and mutators
//Provide access to the private data members 
void Advertisement::setStart (const Date &s){start=s;}

void Advertisement::setClose (const Date &c){close=c;}

void Advertisement::setTitle (string t){title=t;}

void Advertisement::setBody (string b){body=b;}

void Advertisement::setNumber (int n){number=n;}

void Advertisement::setEmail (string email){seller_email=email;}

void Advertisement::setQuantity (int q){quantity=q;}

Date Advertisement::getStart () const{return start;}

Date Advertisement::getClose () const{return close;}

string Advertisement::getTitle() const{return title;}

string Advertisement::getBody() const{return body;}

string Advertisement::getEmail() const{return seller_email;}

int Advertisement::getNumber () const{return number;}

int Advertisement::getQuantity() const{return quantity;}

//Compares Advertisement objects for equality. Two Advertisement objects are equal if their identification numbers are equal.
bool Advertisement::operator==(const Advertisement &adv) const{
	if(number==adv.number) 
		return true;
	else 
		return false;
}

//Reads an Advertisement object from an input stream in the form "title \n email \n quantity \n start-date \n close-date \n body \n"
istream &operator>>(istream &stream, Advertisement &a){
	//char h;
	string t;
	stream>>t;	
	a.setTitle(t);
	//stream>>h;
	//stream>>"\n";

	string e;
	stream>>e;
	a.setEmail(e);
	//stream>>h;
	//stream>>"\n";
	
	int q;
	stream>>q;
	a.setQuantity(q);
      //stream>>h;
	//stream>>"\n";
	
	Date s;
	stream>>s;
	a.setStart(s);
	//stream>>h;
	//stream>>"\n";
	
	Date c;
	stream>>c;
	a.setClose(c);
	//stream>>h;
	//stream>>"\n";
	
	string b;
	stream>>b;
	a.setBody(b); 
    //stream>>h;
	//stream>>"\n";
	
	return stream;
}