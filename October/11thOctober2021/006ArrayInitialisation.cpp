#include<iostream>

using namespace std;

int main() {

	// int A[5] = {10, 20, 30, 40, 50};

	// specifying the size of the array during initialisation is optional
	int A[] = {10, 20, 30, 40, 50};

	// you cannot specify more values in the initializer than the array size
	// int A[5] = {10, 20, 30, 40, 50, 60 , 70}; // error

	// if you give less values in the initializer, rest are filled with default values
	// int A[5] = {10, 20, 30};

	// int A[5] = {}; // all the elements will have the default value, 
				   // which for the built-in types in 0

	int n = sizeof(A) / sizeof(int);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

}