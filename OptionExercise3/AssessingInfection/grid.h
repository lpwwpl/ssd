#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>

using namespace std;

/*
 * IMPORTANT NOTE:
 *
 * For this assignment, you might need to add state to the 
 * class and/or augment existing methods, and/or create private helper 
 * methods, but you should not delare new public methods
 */

const bool INFECTED = true;
const bool NOT_INFECTED = false;
const bool BELONG_COLONY = true;
const bool NOT_BELONG_COLONY = false;

class grid;

class grid {

//private:
public:
    int rows;
    int cols;
    vector<bool> *area;
	//add to tag 
	vector<bool> *colony; 
	//use counter to tag the number of unit 
	int counter;

    int indexof (int row, int col) const;
    bool infected(int row, int col) const;

    grid (string file);
    ~grid ();

    int count (int row, int col);
    friend ostream &operator<<(ostream &stream, const grid& ob);

};

#endif 
