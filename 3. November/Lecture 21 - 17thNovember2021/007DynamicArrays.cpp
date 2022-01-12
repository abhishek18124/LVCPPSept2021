#include<iostream>

using namespace std;

int* resize(int* A, int size, int capacity) {
	cout << "Resizing the array from " << capacity*sizeof(int) << "B  to " << 2*capacity*sizeof(int) << "B" << endl;
	// dynamically create an array of double-capacity
	int* B = new int[2*capacity];
	// copy the contents of the original array in the new array
	for(int i=0; i<size; i++) {
		B[i] = A[i];
	}
	// de-allocate memory reserved for A
	delete [] A;

	return B;
}

int main() {

	int size = 0;
	int capacity = 1;
	int i = 0;

	int* A = new int[capacity];

	int no;
	cin >> no;

	while(no != -1) {
		A[i] = no;
		size++;
		i++;
		if(size == capacity) {
			// resize the array to double capacity
			A = resize(A, size, capacity);
			capacity = 2*capacity;
		}
		cin >> no;
	}

	cout << "Current size = " << size << endl;
	cout << "Current capacity = " << capacity << endl;

	for(int j=0; j<size; j++) {
		cout << A[j] << " ";
	}

	cout << endl;

	return 0;
}