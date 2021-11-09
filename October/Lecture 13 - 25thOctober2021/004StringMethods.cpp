#include<iostream>

using namespace std;

int main() {

	string str = "Hello World";

	// objectName.functionName(...)

	cout << str.length() << endl;
	cout << str.size() << endl; // equivalent to the length() function

	// Append two string objects

	string str1 = "Hello";
	string str2 = "World";

	// str1 = str1+str2; // str1 += str2
	// cout << str1 << endl;

	cout << str1+str2 << endl;
	cout << str1 << endl;

	str1.append(str2); // str1 = str1+str2
	cout << str1 << endl;

	// Comparing two string objects

	string str3("abc");
	string str4("ade");

	cout << (str3 == str4) << endl 
		 << (str3 != str4) << endl
	     << (str3 >  str4) << endl
	     << (str3 <  str4) << endl
	     << (str3 <= str4) << endl
	     << (str3 >= str4) << endl;


	cout << str3.compare(str4) << endl;
	cout << str4.compare(str3) << endl;
	cout << str3.compare(str3) << endl;


	return 0;
}