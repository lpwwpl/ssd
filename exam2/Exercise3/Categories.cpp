//:Categories.h linpeiwen
#include "Categories.h"

const int Categories::TOP_LEVEL = 0;
const int Categories::NO_PARENT = 0;   

//Returns a pointer to a Category object whose identification number matches the parameter.
Category* Categories::operator[](const int& number) {
	Categories::iterator it;
	for(it = objects.begin();it != objects.end();it++) {
		if((*it)->getNumber() == number) {
			return *it;
		}
	}
	return NULL;
}

//This routine adds a Category pointer to the objects vector.
void Categories::add(Category* ptr) {
	objects.push_back(ptr);
}

//Returns a Categories::iterator to the first entry in the objects vector. 
Categories::iterator Categories::begin() {
	return objects.begin();
}

//Returns a Categories::iterator one position past the last entry in the objects vector.
Categories::iterator Categories::end() {
	return objects.end();
}
///:~