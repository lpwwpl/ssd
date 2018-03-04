#include "Group.h"
#include <algorithm>
#include <functional>
 
using namespace std;

Client* Group::operator[](const string& email) {

	Group::iterator it;
	for (it = this->begin(); it != this->end(); it++) {
		if ((*it)->getEmail() == email) {
			return *it;
		}
	}

	return NULL;
}

void Group::add(Client* ptr) {
    objects.push_back (ptr);
}

Group::iterator Group::begin() {
	return objects.begin();
}

Group::iterator Group::end() {
	return objects.end();
}
