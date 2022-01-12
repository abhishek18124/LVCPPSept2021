/*

Implementation of the stack data structure using an array.

*/

#include<iostream>

using namespace std;

template <typename T>
class stack {
	T* arr;
	int t; // stores the index of the last item 
		   // pushed onto the stack
	int n; // stores the maximum capacity of the
		   // stack data structure

public:

	stack(int n) {
		arr = new T[n];
		t = -1;
		this->n = n;
	}

	void push(T data) {
		if(t == n-1) {
			// stack is already full
			return;
		}
		t = t+1;
		arr[t] = data;
	}

	void pop() {
		if(t == -1) {
			// stack is empty
			return;
		}
		t = t-1;
	}

	T top() {
		return arr[t];
	}

	bool empty() {
		return t == -1;
	}

	int size() {
		return t+1;
	}

};

int main() {

	stack<int> s(10);

	s.push(50);
	s.push(40);
	s.push(30);
	s.push(20);
	s.push(10);

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	s.empty() ? cout << "stack is empty!" << endl : cout << "stack is non-empty!" << endl;


	return 0;
}

