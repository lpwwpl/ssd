//: dictionary.h linpeiwen
#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>
#include <fstream>

#include  "hashset.h"
#include  "hashset.cpp"

using namespace std;

class hash_function
{
public:
    hash_function() {}
 
    unsigned int operator()( const string& s )  const {

        // Complete definition
		int mm = 6151;
		unsigned int res = 0;

        for (int i = 0; i < s.size(); i++) {

            res = res * mm + s[i];
        }

        return res;
    }
};

class equality
{
public:
    equality() {}
    bool  operator()( const string& A, const string& B )  const {
		return  (A == B);
    }
};

class Dictionary: public HashSet<string, hash_function, equality> {

    // Complete definition
public:

	//Construct method with no parametre,the main.cpp i need use the construct method.
	Dictionary():HashSet<string, hash_function, equality>() {

	}

	//Construct method with a parametre of filename;
	Dictionary(string filename):HashSet<string, hash_function, equality>() {
		
		ifstream inf(filename.c_str());		
		string word;

		//insert the word into the dictionary.
		while(inf >> word) {

			insert(word);
		}		
	}
};
#endif
///:~