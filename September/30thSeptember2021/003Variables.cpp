#include<iostream>

using namespace std;

int main() {

	// syntax type name;

	int x; // variable declaration - 4Bytes of memory is allocated	

	cout << "Enter an integer : ";
	cin >> x;
	// cout << "You've entered x = " << x << endl;

	int y; // 4Bytes of memory is allocated 

	y = 75; // 75 is assigned to the variable y
	        // RHS of the assignment operator (=) 
			// can be any expression that evaluates
	        // to an integer value since y is an integer

	int z; // 4B of memory is allocated

	z = y; // y is also an expression that evaluates
		   // to a single value which 75, so 75 is assigned to
	       // the variable z


	cout << "x = " << x << '\t'
	     << "y = " << y << '\t'
	     << "z = " << z << endl;


	// float a;
	// float b;
	// float c;

	float a, b, c; // you can declare multiple variable
	 			   // of the same type in the same line

	
	cout << "Enter the values of a, b and c = ";
	cin >> a >> b >> c; // you can also nest the >> operator
	cout << "a = " << a << " b = " << b << " c = " << c << endl;

	return 0;
}