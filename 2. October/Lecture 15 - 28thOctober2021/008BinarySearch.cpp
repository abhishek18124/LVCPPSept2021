#include<iostream>

using namespace std;

int f(int* A, int t, int s, int e) {
	// base case
	if(s > e) {
		// search space has become empty
		return -1;
	}

	// recursive case
	int m = s + (e-s)/2;
	if(A[m] == t) {
		return m;
	} else if(A[m] > t) {
		// reduce your search space from [s, e] to [s, m-1]
		return f(A, t, s, m-1);
	} else {
		// reduce your search space from [s, e] to [m+1, e]
		return f(A, t, m+1, e);
	}
}

int main() {

	int A[] = {10, 20, 30, 40, 50};
	int n = sizeof(A) / sizeof(int);
	int t = 10;

	cout << f(A, t, 0, n-1) << endl;

	return 0;
}