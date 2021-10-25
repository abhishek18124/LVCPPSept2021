#include<iostream>

using namespace std;

int main() {

	string str;

	cout << "Enter a string : ";
	// cin >> str; // '\0' is added by default
	getline(cin, str); // '\0' is added by default
	cout << "You've entered \"" << str << "\"";

	return 0;
}