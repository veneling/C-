#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

/* 1. Make a program that reads line from the keyboard and checks how many upper and lower case letters and other characters are available in the string.
   2. Make a program that demonstrates all the functions learned in lecture */

int main() {
	string s;
	string const uppercase = "UPPERCASE";
	string const lowercase = "lowercase";
	char c;
	unsigned int upper = 0;
	unsigned int lower = 0;
	cout << "Enter string containing upper and lower characters: ";
	getline(cin, s);


	for (unsigned i = 0; i < s.length(); i++) {
		c = s.at(i);
		if (isalpha(c)) {
			isupper(c) ? upper++ : lower++;
			cout << c << " is " << (isupper(c) ? uppercase : lowercase) << endl;
		}
		else {
			cout << c << " is not an alphabetic character" << endl;
		}
	}

	cout << endl << "Your string has " << upper << " uppercase and " << lower << " lowercase characters" << endl;

	return 0;
}