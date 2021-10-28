#include<iostream>

using namespace std;

int f1(int* A, int n, int i) {
	// base case
	if(i == n) {
		// A corresponds to an emtpty array
		return 0;
	}

	// recursive case
	return A[i] + f1(A, n, i+1);
}

int f2(int* A, int n, int i) {
	// base case
	if(i == -1) {
		// A corresponds to an emtpty array
		return 0;
	}

	// recursive case
	return A[i] + f2(A, n, i-1);
}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	cout << f1(A, n, 0) << endl;
	cout << f2(A, n, n-1) << endl;

	return 0;
}