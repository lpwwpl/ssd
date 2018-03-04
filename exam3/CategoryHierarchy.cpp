#pragma warning(disable:4786)

#include <algorithm>
#include "CategoryHierarchy.h"

using namespace std;

const int CategoryHierarchy::NO_PARENT = -1;

Category* CategoryHierarchy::operator[](const int& number) {

	CategoryHierarchy::iterator it;

	for (it = this->begin(); it != this->end(); it++) {
		if ((*it)->getNumber() == number) {
			return *it;
		}
	}
	return NULL;
}


void CategoryHierarchy::findOfferings (int category, Listing::iterator start, 
					Listing::iterator finish, Listing &matches) {
	
	Category* cat = this->operator [](category);
	for (Listing::iterator it = start; it != finish; it++) {
		
		vector<int>::iterator search;
		search = find(cat->itemsBegin(), cat->itemsEnd(), (*it)->getNumber());
		if (search != cat->itemsEnd()) {
			matches.add(*it);
		}
	}

}

void CategoryHierarchy::findOfferingsRecursive (int category, Listing::iterator start, 
					Listing::iterator finish, Listing &matches) {

	findOfferings(category, start, finish, matches);

	vector<int>::iterator it;
	Category* c = this->operator [](category);
	for (it = c->subCategoriesBegin(); it != c->subCategoriesEnd(); it++) {
		findOfferingsRecursive(*it, start, finish, matches);
	}
}

void CategoryHierarchy::add(Category* ptr) {
    objects.push_back (ptr);
}

CategoryHierarchy::iterator CategoryHierarchy::begin() {
	return objects.begin();
}

CategoryHierarchy::iterator CategoryHierarchy::end() {
	return objects.end();
}
