#include<iostream>

using namespace std;

int main() {

	char ch;

	cout << "Enter a character = ";
	cin >> ch;

	// 1st Approach

	// when you compare a character with integer, C++
	// implcitly converts char to int

	// if(ch >= 97 && ch <= 122) {
	// 	cout << ch << " is a lowercase character!" << endl;
	// } else if(ch >= 65 && ch <= 90) {
	// 	cout << ch <<  " is a uppercase character!" << endl;
	// } else {
	// 	cout << ch << " is not an alphabet!" << endl;
	// }

	// Approach 2

	// C++ automatically compares ascii values
	
	if(ch >= 'a' && ch <= 'z') {
		cout << ch << " is a lowercase character!" << endl;
	} else if(ch >= 'A' && ch <= 'Z') {
		cout << ch <<  " is a uppercase character!" << endl;
	} else {
		cout << ch << " is not an alphabet!" << endl;
	}
 
	return 0;
}