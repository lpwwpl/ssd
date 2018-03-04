#include "Listing.h"
#include <algorithm>
#include <functional>
 
using namespace std;

Advertisement* Listing::operator[](const int& number) {

	Listing::iterator it;

	for (it = this->begin(); it != this->end(); it++) {
		if ((*it)->getNumber() == number) {
			return *it;
		}
	}
	return NULL;
}

void Listing::add(Advertisement* ptr) {
    objects.push_back (ptr);
}

Listing::iterator Listing::begin() {
	return objects.begin();
}

Listing::iterator Listing::end() {
	return objects.end();
}
