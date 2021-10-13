#include<iostream>
#include<climits>

using namespace std;

int main() {

	int A[] = {-4, 1, 3, -2, 6, -1, 4, -7};
	int n = sizeof(A) / sizeof(int);

	int maximumSumArraySum = INT_MIN;
	int start; // stores the starting index of the subarray with the maximum sum
	int end; // stores the ending index of the subarray with the maximum sum

	// // Approach 1 - n^3 computations
	
	// // iterate over the starting indices
	// for(int i=0; i<n; i++) {
	// 	// iterate over the ending indices
	// 	for(int j=i; j<n; j++) {
	// 		// compute the sum of the subarray starting at the ith
	// 		// index and ending at the jth index
	// 		int sum = 0;
	// 		for(int k=i; k<=j; k++) {
	// 			sum += A[k];
	// 		}
	// 		if(sum > maximumSumArraySum) {
	// 			maximumSumArraySum = sum;
	// 			start = i;
	// 			end = j;
	// 		}
	// 	}
	// }

	// // Approach 2 - n^2 computations

	// // iterate over the starting indices
	// for(int i=0; i<n; i++) {
	// 	int sum = 0;
	// 	// iterate over the ending indices
	// 	for(int j=i; j<n; j++) {
	// 		// compute the sum of the subarray starting at the ith
	// 		// index and ending at the jth index
			
	// 		// for a subarray that starts at the ith index
	// 		// and ends at the jth index, we just have to
	// 		// add the newly added element i.e. A[j] to the
	// 		// previous sum to compute the subarray sum.

	// 		sum += A[j]; 
			
	// 		if(sum > maximumSumArraySum) {
	// 			maximumSumArraySum = sum;
	// 			start = i;
	// 			end = j;
	// 		}
	// 	}
	// }

	// Approach 3 - n^2 computations + extra space for cumulative sum array

	// calculating cumulative sum array takes n computations
	// and an extra array of size n+1

	int csum[n+1] = {};
	for(int i=1; i<=n; i++) {
		csum[i] = csum[i-1] + A[i-1];
	}

	// iterate over the starting indices
	for(int i=0; i<n; i++) {
		// iterate over the ending indices
		for(int j=i; j<n; j++) {
			// compute the sum of the subarray starting at the
			// ith index and ending at the jth index using the
			// cumulative sum array
			int sum = csum[j+1]-csum[i];
			if(sum > maximumSumArraySum) {
				maximumSumArraySum = sum;
				start = i;
				end = j;
			}
		}
	}




	for(int i=start; i<=end; i++) {
		cout << A[i] << " ";
	}

	cout << endl;
	cout << maximumSumArraySum << endl;

	return 0;
}