#include<iostream>
#include<cmath>

using namespace std;

void generateAllSubsequences(int A[], int n) {
	// iterate over 2^n nos. in the range [0, 2^n-1]
	for(int no=0; no<(1<<n); no++) {
		// iterate over the n-bit repr. of the no. from R->L starting
		// from the 0th bit
		for(int i=0; i<n; i++) {
			if((1<<i)&no) { // (no>>i)&1
				// include the element at the ith index into subsequence
				// if the  ith bit of the no is set
				cout << A[i] << " ";
			}
		}
		cout << endl;
	}
}

int main() {

	int A[] = {1, 2, 3};
	int n = sizeof(A) / sizeof(int);

	generateAllSubsequences(A, n);

	return 0;

}