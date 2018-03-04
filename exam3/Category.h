#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>

using namespace std;

class Category;

istream &operator>>(istream &stream, Category &c);

class Category {

private:
	int number;
	int parent;
	string name;

	vector<int> sub_categories;
	vector<int> items;

public:
	
	Category(void);
	Category(int parent, string name);

	virtual int getNumber(void) const;
	virtual int getParent(void) const;
	virtual string getName(void) const;
	
	virtual void setNumber(int);
	virtual void setParent(int);
	virtual void setName(string);

	virtual void addSubCategory(int);
	virtual void addItem(int);

	virtual vector<int>::iterator itemsBegin();
	virtual vector<int>::iterator itemsEnd();
	virtual vector<int>::iterator subCategoriesBegin();
	virtual vector<int>::iterator subCategoriesEnd();

	virtual bool operator==(const Category& rhs);

};

#endif
