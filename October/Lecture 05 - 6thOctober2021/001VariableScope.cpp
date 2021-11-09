#include<iostream>

using  namespace std;

int x = 100; // global scope

int main() {

	cout << x << endl;

	int x = 10;

	cout << x << endl;

	{	
		
		// as long as scopes are different you can have multiple variables
		// with the same name
		int x = 5;
		int z = 30;
		cout << x << " " << z << endl;
		// use the scope resolution operation :: to access
		// a global variable inside a block that already
		// has a variable with the same name
		cout << ::x << endl;
	}

	int y = ::x;
	cout << y << endl;


	::x = ::x + 20;
	cout << ::x << endl;


	return 0;
}