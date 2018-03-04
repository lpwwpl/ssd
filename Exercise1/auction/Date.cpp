//: Date.cpp linpeiwen
#include "Date.h"
#include <iostream>
#include <cstring>

//Initializes the private data members to default values 
Date::Date():month(0),day(0),year(0),hour(0),minute(0),second(0){
}

//Accepts integers for the day, month, year, hour, minute, and second
Date::Date(int month, int day, int year, int hour, int minute, int second)
		  :month(month),day(day),year(year),hour(hour),minute(minute),second(second) {

}

//The following set and get methods are accessors and mutators provides access to the private data members listed previously 
void Date::setMonth(int& initMonth) {
	month = initMonth;
}
void Date::setDay(int& initDay) {
	day = initDay;
}
void Date::setYear(int& initYear) {
	year = initYear;
}
void Date::setHour(int& initHour) {
	hour = initHour;
}
void Date::setMinute(int& initMinute) {
	minute = initMinute;
}	
void Date::setSecond(int& initSecond) {
	second = initSecond;
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
	if(month == rhs.getMonth() && day == rhs.getDay() && year == rhs.getYear()
		&& hour == rhs.getHour() && minute == rhs.getMinute() && second == rhs.getSecond()) {
		return true;
	} else {
		return false;
	}
}
//Compares Date objects, returns true if the invoking Date object is less than the other Date object 
bool Date::operator< (const Date &rhs) {
	if(year < rhs.getYear() || (year == rhs.getYear() && month < rhs.getMonth()) ||
	  (year == rhs.getYear() && month==rhs.getMonth() && day < rhs.getDay()) || 
	  (year == rhs.getYear() && month==rhs.getMonth() && day == rhs.getDay() && hour < rhs.getHour()) ||
	  (year == rhs.getYear() && month==rhs.getMonth() && day == rhs.getDay() && hour == rhs.getHour() && minute < rhs.getMinute()) ||
	  (year == rhs.getYear() && month==rhs.getMonth() && day == rhs.getDay() && hour == rhs.getHour() && minute == rhs.getMinute()) 
	   && second < rhs.getSecond()) {
		return true;
	} else {
		return false;
	}
}

//Outputs a Date object to an output stream in the form "mm/dd/yyyy hh:nn:ss" 
ostream &operator<<(ostream& out, const Date& date) {
	out << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << " " 
		<< date.getHour() << ":" << date << date.getMinute() << ":" << date.getSecond();
	return out;
}

/*
 * This operator reads a Date object from an input stream. The date will be read from a stream in the following form. 
 * mm/dd/yyyy hh:nn:ss \n
 * 
 */
istream &operator>>(istream& in, Date& date) {

	int month,day,year,hour,minute,second;
	char ch;
	//Use the c++ istream to set the attributes of Date.
	in >> month >> ch >> day >> ch >> year;	
	in >> hour >> ch >> minute >> ch >> second; 
	date.setMonth(month);
	date.setDay(day);
	date.setYear(year);
	date.setHour(hour);
	date.setMinute(minute);
	date.setSecond(second);
	return in;
}
///:~