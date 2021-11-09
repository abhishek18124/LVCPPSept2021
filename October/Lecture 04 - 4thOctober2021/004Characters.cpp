#include<iostream>

using namespace std;

int main() {

	char ch = 'A';

	cout << (int)ch << endl;
	cout << int('a') << endl;

	int ch2 = 'Z'; // implicit type-casting

	cout << ch2 << endl;

	cout << char(ch2) << endl; // explicity type-casting
	cout << char(102) << endl;

	return 0;
}