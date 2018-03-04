#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <functional>

#include "Client.h"

using namespace std;

class Group;

class Group {

protected:
	//Replace "vector<Client*>" to be "map<string, Client*>".
	typedef map<string , Client*> Container;

public:
	typedef Container::iterator iterator;

protected:
	Container objects;

public:
    Client *operator[](const string& email);

	virtual void add(Client* ptr);

	virtual iterator begin();
	virtual iterator end();

};

#endif
