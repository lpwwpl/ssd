#include "Category.h"

using namespace std;

Category::Category(void) :
	parent(0),	name(""), 
	sub_categories(), items() {}

Category::Category(int parent, string name) :
	parent(parent),	name(name), 
	sub_categories(), items() {}

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

void Category::addSubCategory(int category) { 
	sub_categories.push_back(category);
}

void Category::addItem(int item) { 
	items.push_back(item);
}

vector<int>::iterator Category::itemsBegin() {
	return items.begin();
}

vector<int>::iterator Category::itemsEnd() {
	return items.end();
}

vector<int>::iterator Category::subCategoriesBegin() {
	return sub_categories.begin();
}

vector<int>::iterator Category::subCategoriesEnd() {
	return sub_categories.end();
}

bool Category::operator==(const Category& rhs) {
	return (this->getNumber() == rhs.getNumber());
}

istream &operator>>(istream &stream, Category &c) {

  char line[80];
  string name;

  stream.getline(line, 80);
  c.setParent(atoi(line));

  stream.getline(line, 80);
  c.setName(line);

  return stream;
}
