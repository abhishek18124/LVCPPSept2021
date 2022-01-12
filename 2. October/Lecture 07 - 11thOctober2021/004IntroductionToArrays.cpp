#include<iostream>

using namespace std;

int main() {

	int A[5]; // array declaration
	int n = sizeof(A) / sizeof(int); // sizeof(A)/sizeof(A[0])

	// cout << sizeof(A) << endl;

	// read values into array
	for(int i=0; i<n; i++) {
		cin >> A[i];
	}

	// print values in the array
	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	// print values in reverse
	for(int i=n-1; i>=0; i--) {
		cout << A[i] << " ";
	}

	cout << A[10] << endl; // do not exceed valid range of indices,
	                       // you can run into bugs at runtime

}
