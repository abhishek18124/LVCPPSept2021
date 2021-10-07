/*

Write a program to print the following pattern

*
**
***
****
*****
****
***
**
*

here, n i.e. number of rows with increasing pattern is equal to five.

*/

#include<iostream>

using namespace std;

int main() {

	int n = 5;

	// 1st Approach
	
	// for(int i=1; i<=n; i++) {
	// 	// print i stars in the ith row
	// 	for(int j=1; j<=i; j++) {
	// 		cout << "*";
	// 	}
	// 	cout << endl;
	// }

	// for(int i=1; i<n; i++) {
	// 	// print (n-i) stars in the ith row
	// 	for(int j=1; j<=n-i; j++) {
	// 		cout << "*";
	// 	}
	// 	cout << endl;
	// }

	// 2nd Approach

	for(int i=1; i<=2*n-1; i++) {
		if(i <= n) {
			// in the ith row, we have i stars
			for(int j=1; j<=i; j++) {
				cout << "*";
			}
		} else {
			// in the ith row, we have (n-i) stars
			for(int j=1; j<=2*n-i; j++) {
				cout << "*";
			}
		}
		cout << endl;
	}

	return 0;
}