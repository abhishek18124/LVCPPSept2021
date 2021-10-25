#include<iostream>

using namespace std;

int main() {

	string str = "hello hello hello";

	cout << str.find("lo") << endl; // returns the starting idx of the 
								    // first occurrence of the substring
									// in the given string
	cout << str.rfind("lo") << endl; // starting idx of the last occurrence
									 // of the substring in the given string


	cout << str.find("abc") << endl;
	cout << string::npos << endl;

	if(str.find("abc") != string::npos) {
		cout << "substring is present" << endl;
	} else {
		cout << "substring is not present" << endl;
	}


	return 0;
}