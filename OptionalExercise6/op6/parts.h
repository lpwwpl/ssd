//: parts.h linpeiwen
#ifndef _PARTS_H_
#define _PARTS_H_

#include <vector>
#include <map>
#include <string>

using namespace std;

//**************** Part ****************
class Part {
	
public:
	string name;

	// TODO: Finish declaration	
	map<Part*, int> sub_parts;
	Part(string const &n) : name(n) {};
	void describe(void);
	int count_howmany(Part const *p);
};


//**************** NameContainer ****************
class NameContainer  {

private:
	map<string,Part*> name_map;

public:

	NameContainer(void) {};

    //Create an instance of Part with the given name if does not exist in the map then return a pointer to the instance. 
	//If exist return the already instance of Part.  
	Part* lookup(string const &name) {
        // TODO: Finish implementation
		map<string,Part*>::iterator it;
	
		//iterate through the name_map.
		for(it = name_map.begin();it != name_map.end();it++) {
	
			if(it->first == name) {
	
				return it->second;
			} 
		}
		
		Part* new_part = new Part(name);				
		name_map.insert(pair<string,Part*>(name,new_part));	
		
		return new_part;
	}				
};

NameContainer partContainer;  

//**************** Part Member Functions ****************
void Part::describe(void) {
	
    // TODO: Finish implementation

	// List the part name and all of the subparts and their quantities. Use iterators to process the subparts.
	cout << "Part " << name << " sub_parts are:\n" ;
	
	if(sub_parts.empty()) {

		cout << "  It has no sub_parts." << endl;
	} else {
		
		map<Part*,int>::iterator it = sub_parts.begin();
		
		for(;it != sub_parts.end();it++) {	
			
			cout << "  " << it->second << " " << it->first->name << endl;
		}
	}
}

//Counts the number of instances of the part pointed to by p that occur in the invoking object
int Part::count_howmany(Part const *p) {	
		
    // TODO: Finish implementation	
	int count = 0;
	
    //returns the value 1 since this is the base case.
	if(name == p->name) {
		
		return 1;
	} else {
		
		//if reach the end of the tree return 0.
		if(sub_parts.size() == 0) {

			return 0;			
		} else {

			map<Part*,int>::iterator it;
			
			for(it = sub_parts.begin();it != sub_parts.end();it++) {
			
				//recursive method implements the count_howmany.
				count += it->first->count_howmany(p) * it->second;				
			}
		}
	}

	return count;
}

//**************** Miscellaneous Functions ****************
void add_part(string const &x, int q, string const &y) {

    // TODO: Finish implementation

	//To obtain pointers to the Part objects specified by the string parameters.
	Part* partX = partContainer.lookup(x);
	Part* partY = partContainer.lookup(y);

	partX->sub_parts.insert(pair<Part*,int>(partY,q));
}

#endif
///:~
