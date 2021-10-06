#include<iostream>

using namespace std;

int main() {

	const float pi = 3.14; // const variables are by default read-only

	// pi = 22/7.0; // this will lead to an error
	
	int r = 2;

	cout << 2 * pi * r << endl;

	// You cannot assign values to a const variable after declaration
	// you've to initialize them

	// const int x;
	// x = 100;

	return 0;
}