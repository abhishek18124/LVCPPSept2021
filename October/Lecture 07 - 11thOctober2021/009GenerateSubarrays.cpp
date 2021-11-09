#include<iostream>

using namespace std;

int main() {

	int A[] = {10, 20, 30, 40, 50};
	int n = sizeof(A) / sizeof(int);

	// iterate over all the possible starting indices
	for(int i=0; i<n; i++) {
		// iterate over all the possive ending indices
		for(int j=i; j<n; j++) {
			// iterate over elements of a subarray that 
			// starts at index i and ends at index j
			for(int k=i; k<=j; k++){
				cout << A[k] << " ";
			}
			cout << endl;
		}

		cout << endl;
	}

	return 0;
}