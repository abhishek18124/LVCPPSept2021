/*

Recursive version of the Bubble Sort Algorithm

*/

#include<iostream>

using namespace std;

void completePhase(int* A, int n, int i) {
	for(int j=0; j<n-i; j++) {
		if(A[j] > A[j+1]) {
			swap(A[j], A[j+1]);
		}
	}
}

void f(int* A, int n, int i) {
	if(i == n) {
		// you've already done the n-1 phases, so you don't have to do antythin
		return;
	}

	// perform the ith phase yourself
	completePhase(A, n, i);

	// ask your friendt toi do the remaining (n-(i+1)) phases for you
	// starting with (i+1)th phase
	f(A, n, i+1);
}

int main() {

	int A[] = {5, 4, 3, 2, 1};
	int n = sizeof(A) / sizeof(int);

	f(A, n, 1);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}