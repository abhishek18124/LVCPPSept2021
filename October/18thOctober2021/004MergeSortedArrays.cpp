/*

There are two sorted arrays. First one is of size m+n containing only m elements. 
Another one is of size n and contains n elements. Merge these two arrays such that 
the output is sorted without using extra space.

Example :
	
	Input : A[] = [1, 3, 5, 7, - , - , -] B[] = [2, 4, 7]
	Output: [1, 2, 3, 4, 5, 7, 7]

*/

#include<iostream>

using namespace std;

void merge(int A[], int n1, int B[], int n2) {
	int m = n1 - n2;
	int n = n2;

	int i = m-1;
	int j = n-1;
	int k = m+n-1;

	while(i >= 0 && j >=0) {
		if(A[i] > B[j]) {
			A[k] = A[i];
			i--;
		} else {
			A[k] = B[j];
			j--;
		}
		// cout << k << " ";
		k--;
		
	}

	// this code will only run when A exhausts first, i.e. 
	// B still has some remaining elements
	while(j >= 0) {
		A[k] = B[j];
		// cout << k << " ";
		k--;
		j--;
	}

	// cout << endl << i << " " << j << endl;
	// cout << k << endl;

	// if B exhausts first, you dont' have to do anything extra
	// since elements in A are already in their correct position

	// cout << k << endl;

}

int main() {

	int A[7] = {2, 3, 5, 7};
	int n1 = sizeof(A) / sizeof(int);

	int B[] = {1, 4, 7};
	int n2 = sizeof(B) / sizeof(int);

	merge(A, n1, B, n2);

	for(int i=0; i<n1; i++) {
		cout << A[i] << " ";
	}

	cout << endl;
	
	return 0;
}