//:Categories.h linpeiwen
#pragma warning (disable:4786)
#include "Categories.h"

const int Categories::TOP_LEVEL = 0;
const int Categories::NO_PARENT = 0;   

//Returns a pointer to a Category object whose identification number matches the parameter.
Category* Categories::operator[](const int& number) {
	
	iterator it = objects.find(number);
	
	if (it != objects.end() ) {
	
		return it->second;
	}
	
	return NULL;
}

//This routine adds a Category pointer to the objects map<int, Category*>.
void Categories::add(Category* ptr) {
	objects[ptr->getNumber()] = ptr ;
}

//Returns a Categories::iterator to the first entry in the objects map<int, Category*>. 
Categories::iterator Categories::begin() {
	return objects.begin();
}

//Returns a Categories::iterator one position past the last entry in the objects map<int, Category*>.
Categories::iterator Categories::end() {
	return objects.end();
}
///:~