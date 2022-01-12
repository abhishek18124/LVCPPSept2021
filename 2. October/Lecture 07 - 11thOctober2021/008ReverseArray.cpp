#include<iostream>

using namespace std;

int main() {

	int A[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(A) / sizeof(int);

	int i=0;
	int j=n-1;

	while(i < j) {
		swap(A[i], A[j]);
		i++;
		j--;
	}

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}