#include<iostream>

using namespace std;

int main() {

	int x = 10;

	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "&x = " << &x << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << endl;

	cout << endl;

	double y = 20.0;
	cout << "y = " << y << endl;
	cout << "sizeof(y) = " << sizeof(y) << endl;
	cout << "&y = " << &y << endl;
	cout << "sizeof(&y) = " << sizeof(&y) << endl;

	cout << endl;

	char z = 'X';
	cout << "z = " << z << endl;
	cout << "sizeof(z) = " << sizeof(z) << endl;
	cout << "&z = " << &z << endl;
	cout << "sizeof(&z) = " << sizeof(&z) << endl;

	return 0;
}