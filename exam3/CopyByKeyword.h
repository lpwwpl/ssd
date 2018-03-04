#ifndef COPYBYKEYWORD_H
#define COPYBYKEYWORD_H

#include <string>

#include "Advertisement.h"
#include "Listing.h"

using namespace std;

class CopyByKeyword {

private:
	string keyword;
	Listing* listing;

public:
    CopyByKeyword(string keyword, Listing* listing);  
    void operator()(Advertisement *a1) const; 
};

#endif
