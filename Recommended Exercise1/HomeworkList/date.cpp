//:date.cpp linpeiwen
#include "date.h"
using namespace std;

//The default constructor
date::date():day(0),month(0),year(0) {

}

// Initializes the date with meaningful data
date::date(int day,int month,int year):day(day),month(month),year(year) {
}

//Compare with the date given in the parameter 
int date::compareTo(date another_date) {
	if((year == another_date.year) && (month==another_date.month) && (day == another_date.day)) {
		return 0;
	} else if((year>another_date.year) 
		      || ((year == another_date.year)&&(month > another_date.month)) 
		      || ((year == another_date.year)&&(month == another_date.month)&&(day > another_date.day))) {
		return 1;
	} else {
		return -1;
	}
}

//Overwrite << operator,this function should output a date object in the form "mm/dd/yyyy". 
ostream &operator<< (ostream &stream, date d) {
	stream << d.month << '/' << d.day << '/' << d.year;
	return stream;
}
