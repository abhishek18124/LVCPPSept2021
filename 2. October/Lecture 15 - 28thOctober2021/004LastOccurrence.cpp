#include<iostream>

using namespace std;

int f(int* A, int n, int t, int i) {
	// base case
	if(i == -1) {
		// A corresponds to an empty array
		return -1;
	}

	// recursive case

	if(A[i] == t) {
		return i;
	}

	return f(A, n, t, i-1);
}

void allOccurrences(int* A, int n, int t, int i, int& cnt) {
	// base case
	if(i == -1) {
		// A corresponds to an empty array
		return;
	}

	// recursive case

	if(A[i] == t) {
		cnt++;
		cout << i << " ";
	}

	allOccurrences(A, n, t, i-1, cnt);
}

int main() {

	int A[] = {1, 2, 2, 2, 1};
	int n = sizeof(A) / sizeof(int);
	int t = 2;
	int cnt = 0;

	// cout << f(A, n, t, n-1) << endl;


	allOccurrences(A, n, t, n-1, cnt);

	cout << endl << cnt << endl;

	return 0;
}