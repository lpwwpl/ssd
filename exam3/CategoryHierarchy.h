#ifndef CATEGORYHIERARCHY_H
#define CATEGORYHIERARCHY_H

#include <string>
#include <vector>

#include "Category.h"
#include "Listing.h"

using namespace std;

class CategoryHierarchy {

  protected:
	typedef vector<Category*> Container;

  public:
	typedef Container::iterator iterator;

  protected:
	Container objects;

  public:
	static const int TOP_LEVEL;
	static const int NO_PARENT;
    
    virtual void findOfferings (int category, Listing::iterator start, 
					Listing::iterator finish, Listing &matches);
    virtual void findOfferingsRecursive (int category, Listing::iterator start, 
					Listing::iterator finish, Listing &matches);

	virtual Category* operator[](const int& number);

	virtual void add(Category* ptr);

	virtual iterator begin();
	virtual iterator end();

};


#endif
