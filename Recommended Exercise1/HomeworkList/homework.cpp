//:homework.cpp linpeiwen
#include "homework.h"
using namespace std;

//The default constructor
homework::homework ():name(""),assigned_date(date()),due_date(date()){

}

// Initializes the homework with meaningful data
homework::homework (string name, date assigned_date, date due_date):name(name),assigned_date(assigned_date),due_date(due_date) {

}

//Compares with the homework object given in the parameter. 
int homework::compareTo (homework another_homework) {
	return due_date.compareTo(another_homework.due_date);
}

//Overwrite << operator,outputs a homework object using the required format.
ostream &operator<< (ostream &stream, homework h) {
	stream  << "<" << h.name << ">" << ": <" << h.assigned_date << ">" 
		    << " - <" << h.due_date << ">" << endl;
	return stream;
}
