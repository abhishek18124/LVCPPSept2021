#include<iostream>

using namespace std;

int main() {

	float a = 100.79;
	float b = 50.12;
	cout << "a = " << a << " b = " << b << endl;
	cout << "a > b = " << (a > b) << endl;
	cout << "a < b = " << (a < b) << endl;
	cout << "a >= b = " << (a >= b) << endl;
	cout << "a <= b = " << (a <= b) << endl;
	cout << "a == b = " << (a == b) << endl;
	cout << "a != b = " << (a != b) << endl;

	cout << int(true) << endl;
	cout << int(false) << endl;

	bool b1 = a>b;
	cout << b1 << endl;

	// bool b1 = false; // b1 = 0;
	// bool b2 = true; // b2 = 1;

	return 0;
}