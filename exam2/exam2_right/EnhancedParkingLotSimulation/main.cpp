#pragma warning(disable:4786)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stack>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "car.h"

using namespace std;

const int PARKING_SPOTS_PER_AISLE = 3;
const int NUMBER_OF_AISLES = 5;

void handle_arrival(vector<Car>&, vector<stack<string> >&, const string&);
void handle_departure(vector<Car>&, vector<stack<string> >&, const string&);
Car& find_car(vector<Car>&, string);

int main(int argc, char* argv[]) {

    try {

        if (argc != 2) {
            cerr << "Usage:\n" << argv[0] << " data-file";
            return EXIT_FAILURE;
        }    

        ifstream inf(argv[1]);
        if (! inf) {
            cerr << "Could not open " << argv[1];
            return EXIT_FAILURE;
        }

		vector<Car> cars;
		vector< stack<string> > parking_lot(NUMBER_OF_AISLES);

        while (! inf.eof()) {
        
            string action, plate;
            inf >> plate >> action;
        
            if (action == "arrives") {
                handle_arrival(cars, parking_lot, plate);
            } 
            else if (action == "departs") {
                handle_departure(cars, parking_lot, plate);            
            } else {
                cerr << "Unknown action: " << action << endl;
            }
        
        }
        inf.close();    

        cout << "\nHere are all the cars that visited the lot today:\n";

		sort(cars.begin(), cars.end());

		for (vector<Car>::iterator it = cars.begin(); it != cars.end(); it++) {
			cout<< it->getPlate() <<endl;
		}

        // TODO: Output the license plates of all the
        // cars that visited the lot, in alphabetical order		


        return EXIT_SUCCESS;
        
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown exception caught!" << endl;
    }
    
    return EXIT_FAILURE;
}

void handle_arrival(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate) {

	for (vector< stack<string> >::iterator it = parking_lot.begin(); it != parking_lot.end(); it++) {
		
		if (it->size() >= PARKING_SPOTS_PER_AISLE) {
			continue;
		}

		it->push(plate);

		Car car(plate, it - parking_lot.begin());
		cars.push_back(car);
cout<< it - parking_lot.begin() + 1<<","<<car.getPlate()<<endl;
		return;
	}
	cout << "Sorry PORSCHE, the lot is full" << endl;

    // TODO: Handle car arrivals
}

void handle_departure(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate) {

	stack<string> temporary;

	string car_plate;

	Car& car = find_car(cars, plate);
						cout << car.getPlate()
						<< " was moved "
						<< car.getTimesMoved()
						<< " times while while it was parked in the lot"
						<< endl;
	int aisle = car.getAisle();

	stack<string>& depart_aisle = parking_lot[aisle];

	while (!depart_aisle.empty()) {

		car_plate = depart_aisle.top();
		depart_aisle.pop();
		if (car_plate != plate) {
			car = find_car(cars, car_plate);
			car.setTimesMoved(car.getTimesMoved()+1);
			temporary.push(car_plate);
		} else {
			break;
		}
	}

	while (!temporary.empty()) {
		depart_aisle.push(temporary.top());
		temporary.pop();
	}
	
/*
	for (vector< stack<string> >::iterator it = parking_lot.begin(); it != parking_lot.end(); it++) {

		while (!(it->empty())) {	
			car_plate = it->top();
			it->pop();

			if (car_plate == plate) {
					cout << car.getPlate()
						<< " was moved "
						<< car.getTimesMoved()
						<< " times while while it was parked in the lot"
						<< endl;
				break;
			} else {
				Car& car1 = find_car(cars, car_plate);
				car1.setTimesMoved(car.getTimesMoved()+1);
				temporary.push(car_plate);
			}

		}

		while (!temporary.empty()) {
			it->push(temporary.top());
			temporary.pop();
		}
		if (car_plate == plate) {
			break;
		}
	}
*/
    // TODO: Handle car departures
}

Car& find_car(vector<Car>& cars, string plate) {

	Car car(plate);

	vector<Car>::iterator it;

	it = find(cars.begin(), cars.end(), car); 

	return *it;

	// TODO: Return a reference to the 
	// the Car object whose license plate equals 
	// the parameter 'plate'

}