/*

Given a sorted array containing n distinct elements, and a target write a function which 
prints all pairs of numbers in the given array which sum to target.

Example :
	Input  : A[] = {1, 2, 3, 4, 5} Target = 5
	Output : {1, 4}, {2, 3} or 2

*/

#include<iostream>

using namespace std;

// Approach 1 - Naive/BruteForce Approch
int countTargetPairs(int A[], int n, int t) {
	int count = 0;
	// iterate over all the starting indices of the pair
	for(int i=0; i<n-1; i++) {
		// iterate over all the ending indices of the pair
		for(int j=i+1; j<n; j++) {
			if(A[i]+A[j] == t) {
				cout << A[i] << " " << A[j] << endl;
 				count++;
			}
		}
	}

	return count;
}

// Approach 2 - TwoPointer Approch
int countTargetPairsEfficient(int A[], int n, int t) {
	int count = 0;
	int i = 0;
	int j = n-1;

	while(i < j) {
		if(A[i]+A[j] == t) {
			cout << A[i] << " " << A[j] << endl;
			count++;
			i++;
			j--;
		} else if(A[i]+A[j] > t) {
			// jth element is of no use
			j--;
		} else {
			// ith element is of no use
			i++;
		}
	}

	return count;
}




int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);
	int t = 6;

	// out << countTargetPairs(A, n, t) << endl;

	cout << countTargetPairsEfficient(A, n, t) << endl;

	return 0;
}