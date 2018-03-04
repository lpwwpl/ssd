#include "CopyByKeyword.h"

using namespace std;

CopyByKeyword::CopyByKeyword(string keyword, Listing* listing) :
		keyword(keyword), listing(listing) {}  

void CopyByKeyword::operator()(Advertisement *ad) const {
    
	if (string::npos != ad->getTitle().find(keyword) ||
		string::npos != ad->getBody().find(keyword) ||
	    keyword == "")	{
		
		listing->add(ad);
	}  
}
