/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class MaxHeap { 
	vector<int> v;

	void heapify(int i) {
		int max_idx = i; // assume the root node contains the maximum value
		int left_idx = 2*i;
		if(left_idx < v.size() && v[left_idx] > v[max_idx]) {
			max_idx = left_idx;
		}

		int right_idx = 2*i + 1;
		if(right_idx < v.size() && v[right_idx] > v[max_idx]) {
			max_idx = right_idx;
		}

		if(i != max_idx) {  // base is handled here when i == max_idx
			swap(v[i], v[max_idx]);
			heapify(max_idx);
		}

		// you return from here as soon as you hit the base case
	}

public:

	MaxHeap() {
		v.push_back(-1); // to reserve the 0th index
	}

	void push(int data) {
		v.push_back(data); // this may violate the heap property
		int childIdx = v.size()-1;
		int parentIdx = childIdx/2; 
		while(childIdx > 1 && v[childIdx] > v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = childIdx/2;
		}
	}

	void pop() {
		swap(v[1], v[v.size()-1]); // heap property may be violated at the root node
		v.pop_back();
		heapify(1);
	}

	int top() {
		return v[1]; // since root node is the maximum element and assigned the index 1.
	}

	int size() {
		return v.size() - 1; // to avoid counting dummy element at the 0th index
	}

	bool empty() {
		return v.size() == 1; // heap only contains the dummy element
	}

	void print() {
		for(int i=1; i<v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

};



int main() {

	MaxHeap maxHeap;

	maxHeap.push(10);
	maxHeap.push(7);
	maxHeap.push(9);
	maxHeap.push(4);
	maxHeap.push(3);
	maxHeap.push(5);
	maxHeap.push(6);
	maxHeap.push(2);
	maxHeap.push(0);
	maxHeap.push(1);

	cout << "size : " << maxHeap.size() << endl; 
	
	maxHeap.print();

	maxHeap.push(20);

	cout << "size : " << maxHeap.size() << endl;

	maxHeap.print();

	maxHeap.pop();

	cout << "size : " << maxHeap.size() << endl;

	maxHeap.print();

	return 0;
}





