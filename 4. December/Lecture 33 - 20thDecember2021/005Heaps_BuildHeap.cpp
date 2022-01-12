/*

	Given an array of integers, design a algorirthm to build a max_heap in linear time
	without using any extra space (in-place).

*/

#include<iostream>

using namespace std;

void heapify(int* v, int n, int i) {
		int max_idx = i; // assume the root node contains the maximum value
		int left_idx = 2*i;
		if(left_idx < n && v[left_idx] > v[max_idx]) {
			max_idx = left_idx;
		}

		int right_idx = 2*i + 1;
		if(right_idx < n && v[right_idx] > v[max_idx]) {
			max_idx = right_idx;
		}

		if(i != max_idx) {  // base is handled here when i == max_idx
			swap(v[i], v[max_idx]);
			heapify(v, n, max_idx);
		}

		// you return from here as soon as you hit the base case
	}

int main() {
	
	int v[] = {-1, 2, 0, 1, 4, 6, 5, 7, 3};
	int n = sizeof(v) / sizeof(int) ;

	for(int i=n/2-1; i>=1; i--) {
		heapify(v, n, i);
	}

	for(int i=1; i<n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}