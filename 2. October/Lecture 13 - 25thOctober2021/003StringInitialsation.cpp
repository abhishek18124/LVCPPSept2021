#include<iostream>

using namespace std;

int main() {

	string str1 = "Hello World"; // initialsation of string object
	string str2("Coding Blocks");

	cout << str1 << endl << str2 << endl;

	string str3 = str1;
	string str4(str2);
	cout << str3 << endl << str4 << endl;

	char str5[] = "HackerBlocks";
	string str6 = str5;
	string str7(str5);

	cout << str6 << endl << str7 << endl;

	// string str8;

	// cout << str8 << endl;
 
	return 0;
}