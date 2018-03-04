//:homeworklist.cpp linpeiwen
#include "homeworklist.h"
using namespace std;

//Default constructor that initializes the size of the list to zero 
homeworklist::homeworklist():current_size(0) {
}

//Adds an assignment if succeeds and false if maximum number of assignments is already stored.
bool homeworklist::add (homework h) {
	if(current_size >= LIST_MAX) {
		return false;
	} else {
		list[current_size] = h;
		current_size = current_size + 1;
		return true;	
	}
}

//Returns a new homeworklist containing only those homeworks due after the specified date. 
homeworklist homeworklist::dueafter(date d) {
	homeworklist dueafterList;
	for(int i = 0;i < current_size;i++) {
		if(list[i].compareTo(homework("",date(),d)) == 1) {
			dueafterList.add(list[i]);
		}
	}
	return dueafterList; 
}

//Returns a new homeworklist containing only those homeworks due before the specified date. 
homeworklist homeworklist::duebefore(date d) {
	homeworklist duebeforeList;
	for(int i = 0;i < current_size;i++) {
		if(list[i].compareTo(homework("",date(),d)) == -1) {
			duebeforeList.add(list[i]);
		}
	}
	return duebeforeList; 
}

//Returns a new homeworklist containing only those homeworks due exactly on the specified date.
homeworklist homeworklist::dueon(date d) {
	homeworklist dueonList;
	for(int i = 0;i < current_size;i++) {
		if(list[i].compareTo(homework("",date(),d)) == 0) {
			dueonList.add(list[i]);
		}
	}
	return dueonList; 
}

//Overwrite << operator,outputs each homework object stored in the private array on a separate line
ostream &operator<< (ostream &stream, homeworklist hl) {
	for(int i=0;i<hl.current_size;i++) {
		stream << hl.list[i] << endl;
	}
	return stream;
}
