//:Category.h linpeiwen
#pragma warning (disable:4786)
#include "Category.h" 

//constructor
Category::Category(void):number(0), parent(0), name(""), sub_categories(set<Category*> ()), items(set<int>()) {
}

//constructor
Category::Category(int parent, string name):number(0), parent(parent), name(name),
										    sub_categories(set<Category*>()), items(set<int>()) {
	
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
	sub_categories.insert(cg); 
}

void Category::addItem(int it) {
	items.insert(it);
}

//Fills the Listing matches with the advertisements that exist in the invoking category.
void Category::findOfferings (Listing::iterator start, 
							  Listing::iterator finish, Listing &matches) {	

	for(Listing::iterator it = start;it != finish;it++){
	
		Advertisement* ad = *it; 		 
		
		for(set<int>::iterator ad_it = itemsBegin();ad_it != itemsEnd();ad_it++){
			
			if(ad->getNumber() == *ad_it) {
			
				matches.add(ad) ; 
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
	
	
	findOfferings (start, finish, matches);
	
	set<Category*>::iterator it = this->subCategoriesBegin();

	for(; it != this->subCategoriesEnd(); it++)	{

		(*it)->findOfferingsRecursive(start, finish, matches);
	}
}

//Returns a begin iterator for the items set<int>.
set<int>::iterator Category::itemsBegin() {
	return items.begin();
}

//Returns an end iterator for the items set<int>.
set<int>::iterator Category::itemsEnd() {
	return items.end();
}

//Returns a begin iterator for the sub_categories set<Category*>.
set<Category*>::iterator Category::subCategoriesBegin() {
	return sub_categories.begin();
}

//Returns a end iterator for the sub_categories set<Category*>.
set<Category*>::iterator Category::subCategoriesEnd() {
	return sub_categories.end();
}

/* 
 * Compares the invoking Category object and the parameter Category object for equality. Categories are 
 * considered equal if their identification numbers are equal. 
 */
bool Category::operator==(const Category& rhs) {

	if(number == rhs.getNumber()) {
	
		return true;
	} else {
	
		return false;
	}
}

//Reads a Category object from an input stream. The category should input the following data members of the class in the form.
istream &operator>>(istream &stream, Category &c) {

	int parent;
	string name;

	stream>>parent>>name;

	c.setParent(parent);
	c.setName(name);
	
	return stream;
}
///:~