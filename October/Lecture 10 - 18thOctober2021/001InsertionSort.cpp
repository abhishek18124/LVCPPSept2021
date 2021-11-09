#include<iostream>

using namespace std;

void insertionSort(int A[], int n) {
	for(int i=1; i<n; i++) {
		// in the ith phase, we place the element at the ith 
		// index to its correct position in the sorted part
		// of the array
		int key = A[i];
		int j = i-1;
		while(j >= 0 && A[j] > key) {
			// shift the element at the jth index to the (j+1)th index
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

void print(int A[], int n) {
	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

int main() {

	int A[] = {5, 4, 1, 3, 2};
	int n = sizeof(A) / sizeof(int);
	
	print(A, n);

	insertionSort(A, n);

	print(A, n);

	return 0;
}