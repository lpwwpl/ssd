#include "Date.h"

// The default constructor
Date::Date():month(0),day(0),year(0),hour(0),minute(0),second(0){}

// Six parameter constructor 
//Initializes the Date with meaningful data
Date::Date(int Initmonth, int Initday, int Inityear, int Inithour, int Initminute, int Initsecond)
     :month(Initmonth), day(Initday),year(Inityear),hour(Inithour),minute(Initminute),second(Initsecond){}

//Accessors and Mutators
//Provides access to the private data members listed previously 
void Date::setMonth(int& month) {

	this->month = month;
}

void Date::setDay(int& day) {

	this->day = day;
}

void Date::setYear(int& year) {

	this->year = year;
}

void Date::setHour(int& hour) {

	this->hour = hour;
}

void Date::setMinute(int& minute) {

	this->minute = minute;
}

void Date::setSecond(int& second) {

	this->second = second;
}

int Date::getMonth(void) const {

	return month;
}

int Date::getDay(void) const {

	return day;
}

int Date::getYear(void) const {

	return year;
}

int Date::getHour(void) const {

	return hour;
}

int Date::getMinute(void) const {

	return minute;
}

int Date::getSecond(void) const {

	return second;
}

//Compares Date objects for equality 
bool Date::operator== (const Date &rhs) {

	return (month == rhs.getMonth())&&(day == rhs.getDay())&&
		(year==rhs.getYear())&&(hour==rhs.getHour())&&
		(minute == rhs.getMinute())&&(second == rhs.getSecond());
}

//Compares Date objects, returns true if the invoking Date object is less than the parameter Date object 
bool Date::operator< (const Date &rhs) {

	bool k;
    
	if(year < rhs.year)  {
		k = true;
	}else if(year >rhs.year) {
		k = false;
	}else if( month <rhs.month) {
		k = true;
	}else if( month >rhs.month) {
		k = false;
	}else if( day< rhs.day) {
		k =true;
	}else if(day > rhs.day) {
		k =false;
	}else if( hour<rhs.hour) {
		k = true;
	}else if( hour>rhs.hour) {
		k = false;
	}else if( minute<rhs.minute) {
		k = true;
	}else if( minute<rhs.minute) {
		k =false;
	}else if( second<rhs.second) {
		k =true;
	}else {
		k = false;
	}return k;
}

//Outputs a Date object to an output stream in the form "mm/dd/yyyy hh:nn:ss"
ostream &operator<<(ostream& stream, const Date& date) {

	return stream<<date.getMonth()+"/"<<date.getDay()+"/"<<date.getYear()+
		" "<<date.getHour()+":"<<date.getMinute()+":"<<date.getSecond()<<endl;
}


//Reads a Date object from an input stream in the form "mm/dd/yyyy hh:nn:ss\n"
istream &operator>>(istream& stream, Date& date) {

	int date_holder;

	stream>>date_holder;
	date.setMonth(date_holder);

	stream.ignore();
	stream>>date_holder;
	date.setDay(date_holder);

	stream.ignore();
	stream>>date_holder;
	date.setYear(date_holder);

	stream.ignore();
	stream>>date_holder;
	date.setHour(date_holder);

	stream.ignore();
	stream>>date_holder;
	date.setMinute(date_holder);

	stream.ignore();
	stream>>date_holder;
	date.setSecond(date_holder);


	return stream;
}
