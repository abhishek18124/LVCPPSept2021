#include<iostream>

using namespace std;

void isEven(int n) {
	// if(n%2 == 0) {
	// 	cout << n << " is an even number" << endl;
	// } else {
	// 	cout << n << " is an odd number" << endl;
	// }

	n%2 == 0 ? cout << n << " is an even" << endl : cout << n << " is odd" << endl; 
	// return is optional
}

int main() {

	isEven(3);

	return 0;
}