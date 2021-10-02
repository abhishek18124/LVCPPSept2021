#include<iostream>
#include <typeinfo>

using namespace std;

int main() {

	int a = 8;
	int b = 4;

	cout << "a = " << a << " b = " << b << endl;

	cout << "a+b = " << a+b << endl;
	cout << "a-b = " << a-b << endl;
	cout << "a*b = " << a*b << endl;
	cout << "a/b = " << a/b << endl;
	cout << "b%a = " << b%a << endl;

	cout << endl;

	cout << "5+3*4 = " << 5+3*4 << endl;
	cout << "(5+3)*4 = " << (5+3)*4 << endl;

	cout << endl;

	a = 7;

	cout << "a = " << a << " b = " << b << endl;

	cout << "a+b = " << a+b << endl;
	cout << "a-b = " << a-b << endl;
	cout << "a*b = " << a*b << endl;

	/*
		In C++, when you divide an integer by integer
		you get an integer.
	*/

	cout << "a/b = " << a/b << endl; 
	cout << "b%a = " << b%a << endl;

	/*
	
		If you want the result of the division operator
		to be a floating point number then make at-least
		one of numerator or denominator as a floating point number.

	*/

	cout << "a/b = " << a*1.0/b << endl;

	/*
	
		Explicit type-casting i.e you're instructing 
		C++ to change the type of one of the operands
		to another type.

	*/
	cout << "a/b = " << (float)a/b << endl;
	cout << "a/b = " << float(a)/b << endl;
	cout << typeid(true).name() << endl;

	cout << (int)3.14 << endl;
	cout << int(3.14) << endl;

	/*
	
	Implicit type-casting - C++ will automatically
	convert a value from one type to another.

	*/

	int x = 10.98; 
	cout << x << endl;

	return 0;
}