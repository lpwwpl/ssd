#include "Categories.h"

const int Categories::TOP_LEVEL = 0;
const int Categories::NO_PARENT = 0;
/*
* virtual Category* operator[](const int& number); 
* Returns a pointer to a Category object whose identification number 
* matches the parameter.
*/
Category* Categories::operator[](const int& number) {

	vector<Category*>::iterator ci;
	for (ci = objects.begin(); ci < objects.end(); ++ci) {
	
		if((*ci)->getNumber() == number) {
		
			return *ci;
		}
	}
	return NULL;
}

//Returns a Categories::iterator to the first entry in the objects vector 
vector<Category*>::iterator Categories::begin() {

	return objects.begin();
}

//Returns a Categories::iterator one position past the last entry in the objects vector 
vector<Category*>::iterator Categories::end() {

	return objects.end();
}

//This routine adds a Category pointer to the objects vector.
void Categories::add(Category* ptr) {

	objects.push_back(ptr);
}