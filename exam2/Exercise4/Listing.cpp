//:Listing.cpp linpeiwen
#pragma warning(disable:4786)
#include "Listing.h"
#include <algorithm>
#include <list>

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

//The following bool functions create (email,start,close,quantity) predicates to determine object equality.
bool emailLessThan(Advertisement* leftAdvertisement, Advertisement* rightAdvertisement) {

	if(leftAdvertisement->getEmail() < rightAdvertisement->getEmail()) {
	
		return true;
	}

	return false;
}


bool startLessThan(Advertisement* leftAdvertisement, Advertisement* rightAdvertisement) {

	if(leftAdvertisement->getStart() < rightAdvertisement->getStart()) {
	
		return true;
	}

	return false;
}

bool closeLessThan(Advertisement* leftAdvertisement, Advertisement* rightAdvertisement) {

	if(leftAdvertisement->getClose() < rightAdvertisement->getClose()) {
	
		return true;
	}

	return false;
}

bool quantityLessThan(Advertisement* leftAdvertisement, Advertisement* rightAdvertisement) {

	if(leftAdvertisement->getQuantity() < rightAdvertisement->getQuantity()) {
	
		return true;
	}

	return false;
}

//The adapter function,class filterKeyword.used to implements the filter's for_each() stl function.
class filterKeyword {
	
	public:
	string key;
	Listing lt;

	filterKeyword(string kw) : key(kw) {
	
	}

	void operator() (Advertisement* ad) {
	
		if((int)ad->getTitle().find(key) >= 0) {
		
			lt.add(ad);
		} else if((int)ad->getBody().find(key) >= 0) {
	
			lt.add(ad);
		}		
	}
}; 

/*
 * This is a new method. This method returns a copy of the invoking Listing object sorted by the field name given in the parameter.
 * Use an appropriate STL sorting function to sort the advertisements. To sort based on the field name given by the 
 * parameter field, consider using an STL sort function that uses a predicate to determine object equality. The field names 
 * that can be passed into this function are "email," "start," "close," and "quantity." 
 * return a sorted copy of this Listing
 */
  Listing Listing::sort(string field) {
	
	Listing lt;
	vector<Advertisement*>::iterator ad;
	
	//Add all the advertisements to new listing lt.
	for(ad = objects.begin();ad != objects.end();ad++) {
		lt.add(*ad);
	}

	if(field == "email") {

		//stl sort() method
		std::sort(lt.begin(),lt.end(),emailLessThan);
		
	} else if(field == "start") {

		std::sort(lt.begin(),lt.end(),startLessThan);

	} else if(field == "close") {

		std::sort(lt.begin(),lt.end(),closeLessThan);
		
	} else if(field == "quantity") {

		std::sort(lt.begin(),lt.end(),quantityLessThan);

	} 

	return lt;
}

/*
 * This is a new method. This method a new instance of a Listing object that contains only those advertisements 
 * whose name or description contains the string given by the parameter keyword. If the parameter keyword equals 
 * the empty string (""), return a copy of the invoking Listing object. 
 * return a filtered by keyword copy of this Listing.
 */
  Listing Listing::filter(string keyword) {
	
	Listing lt;	
	vector<Advertisement*>::iterator ad;
	
	if(keyword == "") {
		for(ad = objects.begin();ad != objects.end();ad++) {
			lt.add(*ad);
		}
		return lt;
	}

	filterKeyword fk = for_each(objects.begin(),objects.end(),filterKeyword(keyword));
	lt = fk.lt;
	return lt;
}
///:~
