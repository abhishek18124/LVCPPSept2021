#include<iostream>

using namespace std;

int main() {

	int A[] = {5, 4, 7, 6, 8, 3};
	int n = sizeof(A) / sizeof(int);

	// iterate over the phases
	for(int i=1; i<n; i++) {
		// in the ith phase place the largest element in the 
		// unsorted part of the array to its correct position.
		bool isSwappingDone = false; // instead of counting swaps
		                             // maintain a boolean flag to
		                             // check if any swapping is done
									 // in the ith phase of B.S.
		
		for(int j=0; j<n-i; j++) {
			if(A[j] > A[j+1]) {
				swap(A[j], A[j+1]);
				isSwappingDone = true;
			}
		}

		if(!isSwappingDone) { // or isSwappingDone == false
			// in the ith phase you haven't  done any swaps
			// that means the array is now completed sorted
			// so you can stop the bubble sort algorithm.
			break;
		}
	}

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}