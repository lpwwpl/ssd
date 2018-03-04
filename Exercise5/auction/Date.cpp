#include "Date.h"

Date::Date(void) : month(0), day(0), year(0), hour(0), minute(0), second(0) {

}
Date::Date (int month, int day, int year, int hour, int minute, int second)
	: month(month), day(day), year(year), hour(hour), minute(minute), second(second) {

}
void Date::setMonth(int& newMonth) {

	month = newMonth;
}	    
void Date::setDay(int& newDay) {

	day = newDay;
}
void Date::setYear(int& newYear) {

	year = newYear;
}
void Date::setHour(int& newHour) {

	hour = newHour;
}
void Date::setMinute(int& newMinute) {

	minute = newMinute;
}
void Date::setSecond(int& newSecond) {

	second = newSecond;
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
/*Compares Date objects for equality*/
bool Date::operator== (const Date &rhs) {

	if (getSecond() == rhs.getSecond() && getMinute() == rhs.getMinute() && getHour() == rhs.getHour() &&
		getDay() == rhs.getDay() && getMonth() == rhs.getMonth() && getYear() == rhs.getYear()) {
	
		return true;
	}
	return false;
}

/*Compares Date objects, returns true if the invoking Date object is less than the other Date object */
bool Date::operator< (const Date &rhs) {

	if(year < rhs.getYear()) {
	
		return true;
	} 
	else if (year > rhs.getYear()) {
	
		return false;
	}
	else if (month < rhs.getMonth()) {
	
		return true;
	}
	else if (month > rhs.getMonth()) {
	
		return false;
	}
	else if (day < rhs.getDay()) {
	
		return true;
	} 
	else if (day > rhs.getDay()) {
	
		return false;
	} 
	else if (hour < rhs.getHour()) {
		
		return true;
	} 
	else if (hour > rhs.getHour()) {
		
		return false;
	} 
	else if (minute < rhs.getMinute()) {
	
		return true;
	} 
	else if (minute > rhs.getMinute()) {
	
		return false;
	} 
	else if (second < rhs.getSecond()) {
	
		return true;
	} 
	else if (second > rhs.getSecond()) {
	
		return false;
	} 
	return false;
}

/*Outputs a Date object to an output stream in the form "mm/dd/yyyy hh:nn:ss"*/
ostream &operator<<(ostream& stream, const Date& date) {

	 stream << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << " "
			<< date.getHour() << ":" << date.getMinute() << ":" << date.getSecond() << endl;
	 return stream;
}

/*This operator reads a Date object from an input stream. The date will be read from a stream in the following form. 
mm/dd/yyyy hh:nn:ss \n

Notice that the format is terminated by a newline character ('\n'). Make sure your implementation reads 
this ending newline character from the stream. Also, the 'nn' in the format represents the minute portion of the date. 
*/
istream &operator>>(istream& stream, Date& date) {

	char ch;
	int month, day, year, hour, minute, second;
	stream >> month >> ch >> day >> ch >> year >> hour >> ch >> minute >> ch >> second;
	date.setMonth(month);
	date.setDay(day);
	date.setYear(year);
	date.setHour(hour);
	date.setMinute(minute);
	date.setSecond(second);
	return stream;
	
}
