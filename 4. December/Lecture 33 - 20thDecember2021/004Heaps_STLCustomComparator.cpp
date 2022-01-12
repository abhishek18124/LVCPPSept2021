/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class Comparator {
public:
	bool operator()(int a, int b) { // return true when swap is needed, 'b' is the newly inserted data
		// return a < b; // in maxHeap, swap is needed when a < b
		return a > b; // in minHeap, swap is needed when a > b
	}
};

void print(priority_queue<int, vector<int>, Comparator> minHeap) {
	while(!minHeap.empty()) {
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
	cout << endl;
}

int main() {

	priority_queue<int, vector<int>, Comparator> minHeap;

	minHeap.push(10);
	minHeap.push(7);
	minHeap.push(9);
	minHeap.push(4);
	minHeap.push(3);
	minHeap.push(5);
	minHeap.push(6);
	minHeap.push(2);
	minHeap.push(1);

	cout << "size : " << minHeap.size() << endl; 
	
	print(minHeap);

	minHeap.push(0);

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	minHeap.pop();

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	minHeap.pop();

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	return 0;
}