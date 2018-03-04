
#include "Group.h"

//Adds the Client pointer given by the parameter to the vector objects.
void Group::add(Client* ptr) {
	objects.push_back(ptr);
} 

//This returns an iterator to the first Client* in vector objects. 
Group::iterator Group::begin() {
	return objects.begin();
} 

//This returns an iterator to the last Client* in vector objects.
Group::iterator Group::end() {
	return objects.end();
}

//This returns the Client pointer whose object's email equals the parameter email. 
Client* Group::operator[](const string& email) {

	iterator it;

	for(it = objects.begin();it != objects.end();it++) {

		if((*it)->getEmail() == email) {
			return *it;
		}
	}

	return NULL;
}
