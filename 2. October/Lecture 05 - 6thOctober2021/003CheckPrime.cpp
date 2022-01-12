#include<iostream>

using namespace std;

int main() {

	int n = 7;

	// Approach - 1 - with flag

	// bool flag = true; // assume number is a prime number

	// for(int i=2; i<n; i++) {
	// 	if(n%i == 0) {
	// 		// i is a number in the range [2, n-1] that divides
	// 		// n therefore n is not a prime number
	// 		flag = false;
	// 		cout << n  << " is not a prime number" << endl;
	// 		break;
	// 	}
	// }

	// if(flag) {
	// 	cout << n << " is a prime number" << endl;
	// }

	// Approach 1 - without using a flag variable

	int i;
	for(i=2; i<n; i++) {
		if(n%i == 0) {
			// i is a number in the range [2, n-1] that divides
			// n therefore n is not a prime number
			// cout << n << " is not a prime number" << endl;
			break;
		}
	}

	// if(i == n) {
	// 	cout << n << " is a prime number" << endl;
	// } else {
	// 	// i < n i.e. you encountered a break statement within the loop
	// 	// which means n is not a prime number
	// 	cout << n << " is not a prime number" << endl;
	// }

	(i == n) ? cout << n << " is a prime number " << endl : 
	           cout << n << " is not a prime number " << endl;

	return 0;
}