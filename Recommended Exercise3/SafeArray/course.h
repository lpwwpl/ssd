//: course.h linpeiwen
#ifndef COURSE_H
#define COURSE_H
#include "safearray.h"

// The following three sentence must be added.
class course;
// delete the const key word.
ostream& operator<<(ostream&,course& c);
istream& operator>>(istream&, course& c);
int const MAX_LINES = 10;

class course {

  public:
	string name;
    string title;
	safearray<string> description;
     
	//use initial-list to initialize description.
    course() : name(""), title(""),description(safearray<string>(MAX_LINES)) {

	}
	//use initial-list to initialize description.
    course(string name, string title) : 
        name(name), title(title),description(safearray<string>(MAX_LINES)) {	
	}

    friend ostream& operator<<(ostream&,course& c);        
    friend istream& operator>>(istream&,course& c);
};

// overloading operator(<<).
ostream& operator<<(ostream& out,course& c) {

    out << c.name << ": " << c.title << "\n";

    int index = 0;
    while (c.description[index] != "") {
        out << c.description[index++] << "\n";    
    }

    return out;
}

// overloading operator(>>)
istream& operator>>(istream& in, course& c) {

    getline(in, c.name);
    getline(in, c.title);

    string line;
    getline(in, line);
    int number = 0;
    while (line != "") {
        c.description[number++] = line;
        getline(in, line);
    }    
    return in;
}

#endif
