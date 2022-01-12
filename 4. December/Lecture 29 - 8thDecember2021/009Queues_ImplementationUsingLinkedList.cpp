
/*

Implementation of the queue data structure using the linked list data structure.

*/

#include<iostream>
#include<list>

using namespace std;

template <typename T>
class queue {
	list<T> l;

public: 

	void push(T data) {
		l.push_back(data); // or l.push_front(data);
	}

	void pop() {
		l.pop_front(); // or l.pop_back();
	}

	bool empty() {
		return l.empty();
	}

	int size() {
		return l.size();
	}

	T front() {
		return l.front(); // or l.back();
	}

};

int main() {

	queue<int> q;

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


