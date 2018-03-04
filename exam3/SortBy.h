#ifndef SORTBY_H
#define SORTBY_H

#include <string>
#include "Advertisement.h"

using namespace std;

class SortBy {

private:
	string keyField;

public:
    SortBy(string keyField);  
    bool operator()(Advertisement *a1, Advertisement *a2); 
};

#endif
