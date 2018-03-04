//: main.cpp linpeiwen
#include "car.h"
#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	char *filename = NULL;

	//check the parameter needed.
	if ( argc == 2 )
        filename = argv[1];
    else {
        cerr << "Usage: " << argv[0] << " [-n]  file" << endl;
        return EXIT_FAILURE;
    }

	ifstream inf(argv[1]);
	//if inf is error,output the error message.
	if ( !inf ) {
		cerr << "cannot open " << filename << " for input" << endl;
		return EXIT_FAILURE;
	}

	//define varibles
	stack<Car*> cars;
	stack<Car*> temp;
	string state;
	string line;
	string license;
	int MAX_SIZE = 5;	
	Car* car;
	while (inf != NULL) {			
		inf >> license >> state;
		
		//if state equals arrives,let parking lot(cars) pushs new car
		if(state == "arrives") {
			// if over the max size of lot ,then output sorry.
			if(cars.size() >= MAX_SIZE) {					
				cout << "Sorry " << license <<", the lot is full" << endl;
			} else {				
				car = new Car(license,0);
				cars.push(new Car(license,0));						
			}
		//if state equals departs,then do the following thing.
		} else if(state == "departs") {							
				while(cars.top()->getLicense() != license) {					
					cars.top()->increase();	
					temp.push(cars.top());					
					cars.pop();					
				}
				cout << cars.top()->getLicense() << " was moved " << cars.top()->getTimes()
					 << " times while it was here" << endl;
				cars.pop();
				while(!temp.empty()) {
					cars.push(temp.top());
					temp.pop();
				}

		//the remainging cars not depart the lot,output the remaining cars information
		} else {
			while(!cars.empty()) {
				cout << cars.top()->getLicense() << " was moved " << cars.top()->getTimes()
					 << " times while it was here" << endl;	
				cars.pop();
			}
		}
	}
	//delete,else cause memory leak.
	delete car;
	inf.close();
    return EXIT_SUCCESS;
}
///:~