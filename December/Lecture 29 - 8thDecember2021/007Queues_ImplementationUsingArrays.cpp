
/*

Implementation of queues using arrays.

*/

#include<iostream>

using namespace std;

template <typename T>
class queue {
	T* arr;
	int f; // to store the idx from where last item was deleted
	int r; // to store the idx at which the last item was inserted
	int c; // to store number of items inside the queue
	int m; // to store the queue capacity

public:

	queue(int n) {
		m = n;
		arr = new T[m];
		f = r = -1;
		c = 0;
	}

	void push(T data) {
		if(r+1 == m) { // or r == m-1
			// queue is already full
			return;
		}
		r = r+1;
		arr[r] = data;
		c++;
	}

	void pop() {
		if(f == r) {
			// queue is empty
			return;
		}
		f = f+1;
		c--;
	}

	bool empty() {
		return f == r;
	}

	int size() {
		return c; // or r-f
	}

	T front() {
		return arr[f+1];
	}
};

int main() {

	queue<int> q(5);

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	q.empty() ? cout << "queue is empty!" << endl : cout << "queue is non-empty!" << endl;

	return 0;
}