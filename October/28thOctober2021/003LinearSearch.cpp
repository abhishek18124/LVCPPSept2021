#include<iostream>

using namespace std;

int f(int* A, int n, int t, int i) {
	// base case
	if(i == n) {
		// A is empty
		return -1;
	}

	// recursive case
	if(A[i] == t) {
		return i;
	}

	return f(A, n, t, i+1);

}

int main() {

	int A[] = {-2, 0, 4, 3, 10};
	int n = sizeof(A) / sizeof(int);

	int t = 10;

	cout << f(A, n, t, 0) << endl;

	return 0;
}