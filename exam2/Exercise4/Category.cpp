//:Category.h linpeiwen
#include "Category.h"

//constructor
Category::Category(void):number(0), parent(0), name(""), sub_categories(vector<Category*>()), items(vector<int>()) {

}

//constructor
Category::Category(int parent, string name):number(0), parent(parent), name(name),
										    sub_categories(vector<Category*>()), items(vector<int>()) {
	
}

//Accessors and mutators.
int Category::getNumber(void) const {
	return number;
}

int Category::getParent(void) const {
	return parent;
}

string Category::getName(void) const {
	return name;
}

void Category::setNumber(int number) {
	this->number = number;
}

void Category::setParent(int parent) {
	this->parent = parent;
}

void Category::setName(string name) {
	this->name = name;
}

void Category::addSubCategory(Category* cg) {
	sub_categories.push_back(cg);
}

void Category::addItem(int it) {
	items.push_back(it);
}

//Fills the Listing matches with the advertisements that exist in the invoking category.
void Category::findOfferings (Listing::iterator start, 
							  Listing::iterator finish, Listing &matches) {	
	vector<int>::iterator it;
	Listing::iterator lt;
	for(lt = start;lt != finish;lt++) {
		for(it = items.begin();it != items.end();it++) {
			if(*it == (*lt)->getNumber()) {
				matches.add(*lt);
			}
		}
	}
}

/* 
 * This routine fills the Listing matches with the advertisements that exist in the invoking category and 
 * all of its sub-categories. This must be implemented as a recursive function. 
 */
void Category::findOfferingsRecursive (Listing::iterator start, 
									   Listing::iterator finish, Listing &matches) {
	
	vector<Category*>::iterator ct;
	findOfferings(start,finish,matches);

	for(ct = subCategoriesBegin();ct != subCategoriesEnd();ct++) {
		(*ct)->findOfferingsRecursive (start,finish,matches);
	}
}

//Returns a begin iterator for the items vector.
vector<int>::iterator Category::itemsBegin() {
	return items.begin();
}

//Returns an end iterator for the items vector.
vector<int>::iterator Category::itemsEnd() {
	return items.end();
}

//Returns a end iterator for the sub_categories vector.
vector<Category*>::iterator Category::subCategoriesBegin() {
	return sub_categories.begin();
}

/* 
 * Compares the invoking Category object and the parameter Category object for equality. Categories are 
 * considered equal if their identification numbers are equal. 
 */
vector<Category*>::iterator Category::subCategoriesEnd() {
	return sub_categories.end();
}

//Reads a Category object from an input stream. The category should input the following data members of the class in the form.
bool Category::operator==(const Category& rhs) {
	if(number == rhs.getNumber()) {
		return true;
	} else {
		return false;
	}
}
istream &operator>>(istream &stream, Category &c) {

	int parent;
	string name;

	stream>>parent>>name;

	c.setParent(parent);
	c.setName(name);
	
	return stream;
}
///:~