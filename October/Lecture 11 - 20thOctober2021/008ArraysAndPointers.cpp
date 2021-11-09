#include<iostream>

using namespace std;

int main() {

	int A[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(A) / sizeof(int);

	for(int i=0; i<n; i++) {
		cout << i << " " << A[i] << " " << *(A+i) << " " << &A[i] << " " << A+i << endl; 
	}

	return 0;
}