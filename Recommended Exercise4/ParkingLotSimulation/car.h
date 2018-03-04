//: car.h linpeiwen
#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>
using namespace std;

//define class car
class Car {

private:
	string license;
	int times;
public:
    Car();
	Car(string initLicense,int initTimes);
	void setLicense(string license) {
		this->license = license;
	}
	string getLicense() {
		return license;
	}
	void setTimes(int times) {
		this->times = times;
	}
	//increase times by 1
	void increase() {
		times = times + 1;
	}
	int getTimes() {
		return times;
	}

};
#endif
///:~