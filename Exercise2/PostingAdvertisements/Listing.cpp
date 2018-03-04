//:Listing.cpp linpeiwen
#include "Listing.h"

//Adds the Advertisement pointer given by the parameter to the vector objects.
void Listing::add(Advertisement* ptr) {
	objects.push_back(ptr);
} 

//This returns an iterator to the first Advertisement* in vector objects. 
Listing::iterator Listing::begin() {
	return objects.begin();
} 

//This returns an iterator to the last Advertisement* in vector objects.
Listing::iterator Listing::end() {
	return objects.end();
} 

//This returns the Advertisement pointer whose number equals the parameter number. 
Advertisement* Listing::operator[](const int& number) {
	
	iterator it;

	for(it = objects.begin();it != objects.end();it++) {

		if((*it)->getNumber() == number) {
			return *it;
		}
	}

	return NULL;
}
///:~
