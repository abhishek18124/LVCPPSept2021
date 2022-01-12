#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;

	cout << "Enter the value of n = ";
	cin >> n;

	// // Approach - 1

	// int i = 2;

	// while(i < n) {
	// 	if(n%i == 0) {
	// 		cout << n << "is not a prime number" << endl;
	// 		return 0; // terminates the main function and hence the program
	// 	}

	// 	i = i + 1;
	// }

	// cout << n << " is a prime number" << endl;

	// // Approach 2 - using flag variables

	// int i = 2;

	// bool flag = true; // initially I assume n to be prime

	// while(i < n) {
	// 	if(n%i == 0) {
	// 		flag = false;
	// 	}

	// 	i = i+1;
	// }

	// if(flag) {
	// 	cout << n << " is a prime number" << endl;
	// } else {
	// 	cout << n  << " is not a prime number" << endl;
	// }

	// // Approach 3 - Optimised Approach 1

	int i = 2;

	while(i <= sqrt(n)) { // or you can use i*i <= n
		if(n%i == 0) {
			cout << n << " is not a prime number" << endl;
			return 0; // terminates the main function and hence the program
		}

		i = i + 1;
	}

	cout << n << " is a prime number" << endl;

	


	return 0;
}