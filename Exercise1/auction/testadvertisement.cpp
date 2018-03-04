// testadvertisement.cpp
//那几个get和set函数比较简单，一般不会写错，所以不在这个文件的测试范围内。
//这个文件主要测试三个构造函数和运算符“>>”的重载。
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Advertisement.h"

bool testConstructors(void);
bool testInsertion(void);

int main(int argc, char* argv[]) {

    if (!testConstructors()) {
       cerr << "Constructor and\\or accessors failed check\n";
       return EXIT_FAILURE;
    }

    if (!testInsertion()) {
       cerr << "Operator >> failed check\n";
       return EXIT_FAILURE;
    }

    cout << "All tests passed\n";

    return EXIT_SUCCESS;
}

bool testInsertion(void) {

    stringstream s;
    s << "mytitle\nqufanxin_85@msn.com\n10000\n11/25/1985 11:22:33\n07/23/1995 15:25:35\nmybody\n";
    
    Advertisement a;
    s >> a;
    
    if (a.getBody() == "mybody" &&
		a.getEmail() == "qufanxin_85@msn.com" &&
		a.getTitle() == "mytitle" &&
		a.getQuantity() == 10000 &&
		a.getStart().getDay() == 25 &&
        a.getStart().getMonth() == 11 &&
        a.getStart().getYear() == 1985 &&
        a.getStart().getHour() == 11 &&
        a.getStart().getMinute() == 22 &&
        a.getStart().getSecond() == 33 &&
	
		a.getClose().getDay() == 23 &&
        a.getClose().getMonth() == 7 &&
        a.getClose().getYear() == 1995 &&
        a.getClose().getHour() == 15 &&
        a.getClose().getMinute() == 25 &&
        a.getClose().getSecond() == 35) {
    
        return true;   
    }
    else {
        return false;
    }
}

bool testConstructors(void) {
	Date start1(11,25,1985,11,22,33);
	Date close1(7,23,1995,15,25,35);
    
	Advertisement b("mytitle","qufanxin_85@msn.com","mybody",start1,close1,100);
	Advertisement c(b);		
		if (b.getBody() == "mybody" &&
		b.getEmail() == "qufanxin_85@msn.com" &&
		b.getTitle() == "mytitle" &&
		b.getQuantity() == 100 &&
		b.getStart().getDay() == 25 &&
        b.getStart().getMonth() == 11 &&
        b.getStart().getYear() == 1985 &&
        b.getStart().getHour() == 11 &&
        b.getStart().getMinute() == 22 &&
        b.getStart().getSecond() == 33 &&
	
		b.getClose().getDay() == 23 &&
        b.getClose().getMonth() == 7 &&
        b.getClose().getYear() == 1995 &&
        b.getClose().getHour() == 15 &&
        b.getClose().getMinute() == 25 &&
        b.getClose().getSecond() == 35 &&
		
		
		
		c.getBody() == "mybody" &&
		c.getEmail() == "qufanxin_85@msn.com" &&
		c.getTitle() == "mytitle" &&
		c.getQuantity() == 100 &&
		c.getStart().getDay() == 25 &&
        c.getStart().getMonth() == 11 &&
        c.getStart().getYear() == 1985 &&
        c.getStart().getHour() == 11 &&
        c.getStart().getMinute() == 22 &&
        c.getStart().getSecond() == 33 &&
	
		c.getClose().getDay() == 23 &&
        c.getClose().getMonth() == 7 &&
        c.getClose().getYear() == 1995 &&
        c.getClose().getHour() == 15 &&
        c.getClose().getMinute() == 25 &&
        c.getClose().getSecond() == 35) {
    
        return true;   
    }
    else {
        return false;
    }
}
