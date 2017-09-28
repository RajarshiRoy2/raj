#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited
// helper function to remove white spaces
static void removewhitespaces(string & value)
{
	locale loc;
	for (int i = 0; i<value.length(); i++)
		if (value[i] == ' ') value.erase(i, 1);
	}
}
// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}
static void checkforcharecter(string & value) //to check if alphabets only or not
{
	locale loc;
	bool true1;
	for (int i = 0; i<value.size(); i++) 
	{
		if (isalpha(value[i])
		{
			true1 = true;
		}
		else
		{
			true1 = false;
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
	void FindPalindrome::recursiveFindPalindromes(vector<string>
		candidateStringVector, vector<string> currentStringVector)
	{
		int candidate_size, current_String_size, n, m;
		string candidateStringVector1;
		bool pal;
		candidate_size = candidateStringVector.size(); //size of candidateStringVector
		current_String_size = currentStringVector.size();//size of currentStringVector
		candidateStringVector1 = candidateStringVector + currentStringVector[n];
		n++;
		pal = FindPalindrome(candidateStringVector1);
		if (pal == false || n == current_String_size)
		{
			return m;
		}
		else
		{
			m++;
			return recursiveFindPalindromes(candidateStringVector, currentStringVector1)
		}
	}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	 my_string = new mystring("kayak");
	// TODO need to implement this...
}

FindPalindrome::~FindPalindrome()
{
	mystring = NULL;
	delete mystring;
	// TODO need to implement this...
}

int FindPalindrome::number() const
{
	// TODO need to implement this...

	return 10;
}

void FindPalindrome::clear()
{
	// TODO need to implement this...
	mystring = NULL;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value) //first bool 
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	vector<vector<string>> returnThingie;
	return returnThingie;
}

