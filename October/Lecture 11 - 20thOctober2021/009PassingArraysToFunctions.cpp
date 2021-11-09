#include<iostream>

using namespace std;

int computeSum(int* A, int n) { // use int A[] or int* A
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += *(A+i); // use A[i]
	}

	return sum;
}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	cout << computeSum(&A[0], n) << endl; // use A 

	int* ptr = A;

	cout << computeSum(ptr, n) << endl;

	int B[] = {10, 20, 30, 40, 50};

	ptr = B;

	cout << computeSum(ptr, n) << endl;

	// A = B; // error, you cannot assign value 

	return 0;
}