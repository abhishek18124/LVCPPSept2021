#include<iostream>

using namespace std;

int main() {

	int a, b, c;

	cout << "Enter the value of a = ";
	cin >> a;

	cout << "Enter the value of b = ";
	cin >> b;

	cout << "Enter the value of c = ";
	cin >> c;

	// Approach 1

	if(a>b && a>c) {
		cout << a << " is the largest" << endl;
	} else if(b > c) {
		cout << b << " is the largest" << endl;
	} else {
		cout << c << " is the largest(inside else)" << endl;
	}

	cout << "Outside if-else-if-else" << endl;

	// if(a > b) {
	// 	if(a > c) {
	// 		cout << a < " is the largest" << endl;
	// 	} else {
	// 		cout << c << " is the largest" << endl;
	// 	}
	// }


	return 0;
}