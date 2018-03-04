#include "Category.h"

/*
* Default constructor 
* Initializes the private data members to default values 
*/
Category::Category() : number(0), parent(0), name("") {

}

/*
* Two parameter constructor 
* Accepts parameters for parent id and name 
*/
Category::Category(int parent, string name) : parent(parent), name(name) {

}

/*
* Accessors and mutators 
* Provides access to the data members of the class
*/
int Category::getNumber(void) const {

	return number;
}
int Category::getParent(void) const {

	return parent;
}
string Category::getName(void) const {

	return name;
}
	
void Category::setNumber(int new_number) {

	number = new_number;
}
void Category::setParent(int new_parent) {

	parent = new_parent;
}
void Category::setName(string new_name) {

	name = new_name;
}

/*
* virtual vector<int>::iterator itemsBegin(); 
* Returns a begin iterator for the items vector 
*/
vector<int>::iterator Category::itemsBegin() {

	return items.begin();
}

/*
* virtual vector<int>::iterator itemsEnd(); 
* Returns an end iterator for the items vector
*/
vector<int>::iterator Category::itemsEnd() {

	return items.end();
}

/*
* virtual vector<Category*>::iterator subCategoriesBegin(); 
* Returns a begin iterator for the sub_categories vector 
*/
vector<Category*>::iterator Category::subCategoriesBegin() {

	return sub_categories.begin();
}

/*
* virtual vector<Category*>::iterator subCategoriesEnd(); 
* Returns an end iterator for the sub_categories vector 
*/
vector<Category*>::iterator Category::subCategoriesEnd() {

	return sub_categories.end();
}

/*
* virtual void addItem (int item); 
* Adds an advertisement number to the items vector 
*/
void Category::addItem(int new_item) {

	items.push_back(new_item);
}

/*
* virtual void addSubCategory (Category*); 
* Adds a category to the sub_categories vector 
*/
void Category::addSubCategory(Category* newSubCategory) {

	sub_categories.push_back(newSubCategory);
}

/*
* virtual void findOfferings (Listing::iterator start, Listing::iterator finish, Listing &matches); 
* Fills the Listing matches with the advertisements that exist in the invoking category. 
*/
void Category::findOfferings (Listing::iterator start, 
							  Listing::iterator finish, Listing &matches) {
	vector<int>::iterator ii;
	Listing::iterator s;
	for(s = start; s < finish; ++s) {
	
		for(ii = itemsBegin(); ii < itemsEnd(); ++ii) {
		
			if ((*s)->getNumber() == *ii) {
			
				matches.add(*s);
			}
		}
	}
}

/*
* void findOfferingsRecursive (Listing::iterator start, Listing::iterator finish, Listing &matches); 
* This routine fills the Listing matches with the advertisements that exist in the invoking category 
* and all of its sub-categories. This must be implemented as a recursive function.
*/
void Category::findOfferingsRecursive (Listing::iterator start, 
									   Listing::iterator finish, Listing &matches) {

	vector<Category*>::iterator ci;
	findOfferings(start, finish, matches);
	for(ci = sub_categories.begin(); ci < sub_categories.end(); ++ci) {
	
		(**ci).findOfferingsRecursive(start, finish, matches);
	}
}

/*
* istream &operator>>(istream &stream, Category &b); 
* Reads a Category object from an input stream. The category 
* should input the following data members of the class in the form 
* parent_id \n name \n
*/
istream &operator>>(istream &stream, Category &c) {

	int p;
	string n;
	stream >> p >> n;
	c.setName(n);
	c.setParent(p);
	return stream;
}
/*int number;
	int parent;
	string name;
	vector<Category*> sub_categories;
	vector<int> items;*/

/*
* virtual bool operator== (const Category &rhs); 
* Compares the invoking Category object and the parameter 
* Category object for equality. Categories are considered 
* equal if their identification numbers are equal.
*/
bool Category::operator==(const Category& rhs) {

	if (rhs.getNumber() == getNumber()) {
	
		return true;
	}
	return false;
}