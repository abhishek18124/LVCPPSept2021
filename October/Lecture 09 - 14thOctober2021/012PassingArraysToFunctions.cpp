#include<iostream>

using namespace std;

int computeSum(int A[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += A[i];
	}

	A[0] = 100;

	return sum;
}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	cout << computeSum(A, n) << endl;

	cout << A[0] << endl;

	return 0;
}