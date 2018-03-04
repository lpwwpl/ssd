#include "Group.h"

//Adds the Client pointer given by the parameter to the vector objects.
void Group::add(Client* ptr) {

	objects.push_back(ptr);
}

//This returns an iterator to the first Client* in vector objects.
vector<Client*>::iterator Group::begin() {

	iterator it;
	it = objects.begin();
	return it;
}

//This returns an iterator to the last Client* in vector objects.
vector<Client*>::iterator Group::end() {

	iterator it;
	it = objects.end();
	return it;
}

//This returns the Client pointer whose object's email equals the parameter email.
Client* Group::operator[](const string& email) {

	iterator it;
	for (it = objects.begin(); it != objects.end(); it++) {
	
		if (it == NULL) {
		
			return NULL;
		}
		if ((*it)->getEmail() == email) {
		
			cout << (*it)->getEmail() << "  true" << endl;
			return *it;
		}
	}
	return NULL;
}