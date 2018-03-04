//: grid.cpp linpeiwen
#include <iostream>
#include <fstream>

using namespace std;

#include "grid.h"

// You do not need to alter function indexof.
int grid::indexof (int row, int col) const {
  return row*cols+col;
}

// You do not need to alter function infected.
bool grid::infected(int row, int col) const {
  return (area->operator[](indexof(row, col)) == INFECTED);
}

// You may need to alter the constructor
grid::grid (string file) {
  
  ifstream grid_file;

  this->counter = counter;
  grid_file.open (file.c_str());

  grid_file >> rows;
  grid_file >> cols;
  
  counter = 0;
  area = new vector<bool>(rows*cols, NOT_INFECTED);
  colony = new vector<bool>(rows*cols, NOT_INFECTED);

  while (true) { 
  
    int blob_row;
    int blob_col;

    grid_file >> blob_row;  
    grid_file >> blob_col;  

    if (grid_file.eof()) {
        break;
    }

    area->operator[](indexof(blob_row,blob_col)) = INFECTED;
//	colony->operator[](indexof(blob_row,blob_col)) = BELONG_COLONY;
  }
  
  grid_file.close();
}

// You may need to alter the destructor
grid::~grid () {
	delete colony;
	delete area;
}


// You will need to alter this function to display the
// plus signs (+) next to the cells that belong to
// a counted colony.
ostream &operator<<(ostream &stream, const grid& ob) {

  for (int row=0; row < ob.rows; row++) { 
    
    for (int col=0; col < ob.cols; col++) {

		stream << ob.area->operator[](ob.indexof(row, col));
		
		if(ob.colony->operator[](ob.indexof(row,col)) == BELONG_COLONY) {
			stream << "+  ";
		} else {
			stream << "   ";
		}
    }

    stream << endl;
  }

  stream << endl;
  return stream;
}

// Replace the return statement in this function with your
// recursive implementation of this method */
int grid::count (int row, int col) {

    if (row >= rows || col > cols || row < 0 || col < 0)  {
		return 0;
	}

	if(area->operator [](indexof(row,col)) == NOT_INFECTED  || colony->operator[](indexof(row,col)) == BELONG_COLONY){
	    return 0;
	} else{
		counter++;
		colony->operator[](indexof(row,col)) = BELONG_COLONY;
		count(row + 1, col);     //underside
		count(row + 1, col + 1); //right down
		count(row, col + 1);  // right
		count(row - 1, col + 1);//top right corner
        count(row - 1, col);  // top
        count(row - 1, col - 1);//top left corner
	    count(row, col -1);   // left
	    count(row + 1, col -1); // left down
	}
	return counter;
}



