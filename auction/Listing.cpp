#pragma warning(disable:4786)
#include "Listing.h"
#include <list>
#include <algorithm>

//Adds the Advertisement pointer given by the parameter to the vector objects.
void Listing::add(Advertisement* ptr) {

	objects.push_back(ptr);
}

//This returns an iterator to the first Advertisement* in vector objects. 
vector<Advertisement*>::iterator Listing::begin() {

	iterator it;
	it = objects.begin();
	return it;
}

//This returns an iterator to the last Advertisement* in vector objects. 
vector<Advertisement*>::iterator Listing::end() {

	iterator it;
	it = objects.end();
	return it;
}

//This returns the Advertisement pointer whose number equals the parameter number. 
//Note, this is not the same as returning the pointer that exists and at index number.
Advertisement* Listing::operator[](const int& number) {

	iterator it;
	for (it = objects.begin(); it != objects.end(); it++) {
	
		if (it == NULL) {
		
			return NULL;
		}
		if ((*it)->getNumber() == number) {
		
			return *it;
		}
	}
	return NULL;
}

class fliteKey {
public:
	string key;
	Listing newlisting;
	fliteKey(string nk) : key(nk){
	
	}
	void operator() (Advertisement* pa) {
	
		if((int)pa->getTitle().find(key) >= 0) {
		
			newlisting.add(pa);
		}else if((int)pa->getBody().find(key) >= 0) {
		
			newlisting.add(pa);
		}
		
	}
};

/*
* This is a new method. This method returns a copy of the invoking Listing object 
* sorted by the field name given in the parameter. Use an appropriate STL sorting 
* function to sort the advertisements. To sort based on the field name given by the 
* parameter field, consider using an STL sort function that uses a predicate to 
* determine object equality. The field names that can be passed into this function 
* are "email," "start," "close," and "quantity." 
*/
bool cpString(Advertisement* paa, Advertisement* pab) {

	if(paa->getEmail() < pab->getEmail()) {
	
		return true;
	}
	return false;
}

bool cpSDate(Advertisement* paa, Advertisement* pab) {

	if(paa->getStart() < pab->getStart()) {
	
		return true;
	}
	return false;
}

bool cpCDate(Advertisement* paa, Advertisement* pab) {

	if(paa->getClose() < pab->getClose()) {
	
		return true;
	}
	return false;
}

bool cpint(Advertisement* paa, Advertisement* pab) {

	if(paa->getQuantity() < pab->getQuantity()) {
	
		return true;
	}
	return false;
}

//"email," "start," "close," and "quantity."
Listing Listing::sort(string field) {

	Listing newlisting;
	
	vector<Advertisement*>::iterator ia;
	
	for(ia = objects.begin(); ia != objects.end(); ia++) {
	
		newlisting.add(*ia);
	}
	cout << (*newlisting.begin())->getEmail() <<endl;
	if(field == "email") {
	
		std::sort(newlisting.begin(), newlisting.end(), cpString);
	} else if(field == "start") {
	
		std::sort(newlisting.begin(), newlisting.end(), cpSDate);
	} else if(field == "close") {
	
		std::sort(newlisting.begin(), newlisting.end(), cpCDate);
	} else if (field == "quantity") {
	
		std::sort(newlisting.begin(), newlisting.end(), cpint);
	}
	return newlisting;
}

Listing Listing::filter(string keyword) {

	Listing newlisting;
	vector<Advertisement*>::iterator ia;

	if(keyword == "") {
	
		for(ia = objects.begin(); ia != objects.end(); ia++) {
		
			newlisting.add(*ia);
		}
		return newlisting;
	}
	fliteKey fk = for_each(objects.begin(), objects.end(), fliteKey(keyword));
	newlisting = fk.newlisting;
	return newlisting;
}

