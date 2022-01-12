/*

	STL implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<queue>

using namespace std;

void print(priority_queue<int> maxHeap) {
	while(!maxHeap.empty()) {
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}
	cout << endl;
}

int main() {

	priority_queue<int> maxHeap;

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
	
	print(maxHeap);

	maxHeap.push(20);

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	maxHeap.pop();

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	maxHeap.pop();

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	return 0;
}