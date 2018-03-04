#include "Listing.h"

//adds the Advertisement pointer given by the parameter to the vector objects
void Listing::add(Advertisement* ptr){

	objects.push_back(ptr);

}

//returns an iterator to the first Advertisement* in vector objects
Listing::iterator Listing::begin(){

	return objects.begin();

}

//returns an iterator to the last Advertisement* in vector objects
Listing::iterator Listing::end(){

	return objects.end();

}

//returns the Advertisement pointer whose number equals the parameter number
Advertisement* Listing::operator[](const int& number){

	for(Listing::iterator it = objects.begin(); it != objects.end(); it++){

		if ((*it)->getNumber() == number){

			return *it;
		} 
			
	}

	return NULL;
}
