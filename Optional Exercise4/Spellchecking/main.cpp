//:main.cpp linpeiwen
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#pragma warning(disable:4786)

#include "dictionary.h"

using namespace std;

void lower(string& s);
string strip_punct(const string& s);
void check_spelling(ifstream& in, Dictionary& dict);

//Transposing of adjacent letters 
void transpose(string& s,Dictionary& dict) {

	//Define a new dictionary object to store the corrected word,in order not 
	//output the right word more than once.
	Dictionary dt;
	int size = s.length();
	char temp = ' ';
	string str = s;

	for(int i = 0;i<str.length() - 1;i++) {

		int j;
		j = i + 1;

		//swap the str[i] and str[j]
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;

		if(dict.search(str) && dt.search(str) == false) {

			dt.insert(str);
			cout<<"\t\t"<<str<<endl;
		}

		//Let str be back to the beginning s.
		str = s;
	}
}

//Removal of each letter  
void remove(string& s,Dictionary& dict) {

	//Define a new dictionary object to store the corrected word,in order not 
	//output the right word more than once.
	Dictionary dt;
	int size = s.length();
	string str = s;

	for(int i = 0;i < str.length();i++) {

		str.erase(i,1);

		if(dict.search(str) && dt.search(str) == false) {

			dt.insert(str);
			cout<<"\t\t"<<str<<endl;
		}

		str = s;	
	}
}

//Replacement of each letter 
void replace(string& s,Dictionary& dict) {

	//Define a new dictionary object to store the corrected word,in order not 
	//output the right word more than once.
	Dictionary dt;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	int size = s.length();	
	string str = s;

	for(int i = 0;i < str.length();i++) {

		for(int j = 0;j < alphabet.length();j++){

			//Implement replace operation.
			str[i] = alphabet[j];

			if(dict.search(str) && dt.search(str) == false) {

				dt.insert(str);
				cout<<"\t\t"<<str<<endl;
			} 

			str = s; 	
		}
	}
}
 
//Inserting any letter at any position in a word 
void insert(string& s,Dictionary& dict) {

	Dictionary dt;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	int size = s.length();
	string str = s;

	for(int i = 0;i <= str.length() ;i++) {

		for(int j = 0;j < alphabet.length();j++){

			//insert method takes three parametres implements any letter at any position in a word.
			str.insert(i,1,alphabet[j]);

			if(dict.search(str) && dt.search(str) == false) {
				
				dt.insert(str);
				cout<<"\t\t"<<str<<endl;
			}

			str = s;
		}
	}
}

int main(int argc, char* argv[]) {

	// Output usage message if improper command line args were given.
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " wordlist_filename input_file\n";
		return EXIT_FAILURE;
	}

	ifstream inf(argv[2]);
	if (! inf) {
		cerr << "Could not open " << argv[2] << "\n";
		return EXIT_FAILURE;
	}

	// Read dictionary, but let user know what we are working on.
	cout << "Loading dictionary, this may take a while...\n";

	Dictionary d(argv[1]);
	
	check_spelling(inf, d);

	inf.close();

	return EXIT_SUCCESS;
}

void check_spelling(ifstream& in, Dictionary& dict) {

	int line_number = 0;

	while (in) {

		line_number++;

		string line;
		getline(in, line);

  	    stringstream ss (stringstream::in | stringstream::out);
		ss << line;

		string word;
		while (ss >> word) {			

            // TODO: Complete the spell check of each word
			//The following is my code,implements the suggestion.
			
			//temp variable to store the original word.
			string temp;

			lower(word);
			word = strip_punct(word);
			temp = word;

			if(dict.search(word)) {
				
			} else {
				//output the result.
				cout << "line " << line_number << ": '" << word << "'\n"
					 << "\t" <<"suggestions:" << endl;

				transpose(word,dict);

				//word to be the original word.
				word = temp;
				remove(word,dict);

				//word to be the original word.
				word = temp;
				replace(word,dict);

				//word to be the original word.
				word = temp;
				insert(word,dict);
			}

		}
	}

}

void lower(string& s) {

    // Ensures that a word is lowercase
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}

string strip_punct(const string& s) {

	// Remove any single trailing
	// punctuation character from a word.  
	if (ispunct(s[s.length() - 1]) ) {
		return s.substr (0, s.length() - 1);
	}
	else {
		return s;
	}
}
///:~

