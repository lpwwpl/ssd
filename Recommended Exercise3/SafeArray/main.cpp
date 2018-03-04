//: main.cpp linpeiwen
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
using namespace std;

#include "safearray.h"
#include "course.h"

// modify the parameter of the following function. 
void init_courses(safearray<course>& courses);
void display_menu(safearray<course>& courses);

const int NUM_COURSES = 10;
const int QUIT = 99;

int main(int argc, char* argv[]) {

	// modify the prior array to be a safearray array type. 
    safearray<course> courses(NUM_COURSES);
    init_courses(courses);

    int choice = 0;    
	while (choice != QUIT) {
        display_menu(courses);
        cout << "Enter number of course to see more information on\n";	
		try {
			cin >> choice;
			cout << "\n";
			// together with the following choice = 0 implements avoiding letter input.
			cin.sync();
			cin.clear();
			// use try catch sentence,recover from this error and continue executing.
			if (choice >= 1 && choice <= NUM_COURSES) {
				cout << courses[choice - 1] << "\n\n";
				// choice must again be 0.
				choice = 0;
			} else if(choice == 99) {
				return EXIT_SUCCESS;
			} else {
				throw exception("Warning!\n");
			} 
		// handle all type of exceptions.
		} catch(exception& e) {
			cerr << e.what() << "Error!You can enter an int not in 1 to 10 or 99." << "\n\n";
		}		
    }
    return EXIT_SUCCESS;
}

void display_menu(safearray<course>& courses) {

	// use try catch sentence,recover from this error and continue executing.
	try {
		for (int i = 1; i <= NUM_COURSES; i++) {
			cout << i << ". " << courses[i - 1].name << "\n";
		} 
		cout << "99. Quit\n";
	} catch(out_of_range& e) {
		cerr<<e.what()<<endl;
	} catch(exception& e) {
		cerr << e.what() << endl;
	}
}

void init_courses(safearray<course>& courses) {
    
    ifstream inf("courses.txt");
    if (! inf) {
        cerr << "Could not open courses.txt" << endl;
        exit(EXIT_FAILURE);
    }
	// use try catch sentence,recover from this error and continue executing.
	try{
		for (int i = 0; i < NUM_COURSES; i++) {
			inf >> courses[i];
		} 
    } catch(out_of_range& e) {
		cerr<<e.what()<<endl;
	} catch(exception& e) {
		cerr << e.what() << endl;
	}
    inf.close();
}

