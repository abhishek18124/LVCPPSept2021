#include<iostream>

using namespace std;

int binarySearch(int A[], int n, int key) {

	int s = 0;
	int e = n-1;

	while(s <= e) {
		int m = s + (e-s)/2; // to avoid integer overflow
		if(A[m] == key) {
			// you've found the key at the mid index
			return m;
		} else if(A[m] > key) {
			// reduce the search space from [s, e] to [s, m-1]
			e = m-1;
		} else {
			// reduce the search space from [s, e] to [m+1, e]
			s = m+1;
		}
	}
	return -1;	
}

int main() {

	int A[] = {-5, 0, 2, 6, 9};
	int n = sizeof(A) / sizeof(int);

	int key = -100;

	cout << binarySearch(A, n, key) << endl;

	return 0;
}