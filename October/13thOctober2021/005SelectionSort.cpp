#include<iostream>

using namespace std;

int main() {

	int A[] = {5, 4, 1, 3, 2};
	int n = sizeof(A) / sizeof(int);

	// iterate over the phases
	for(int i=0; i<n-1; i++) {
		// in the ith phase of the selection sort algorithm 
		// we place the smallest element in the unsorted part
		// of the array to its correct position which is the 
		// ith index
		int min_idx = i;
		for(int j=i+1; j<n; j++) {
			if(A[j] < A[min_idx]) {
				min_idx = j;
			}
		}
		swap(A[min_idx], A[i]);
	}

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}