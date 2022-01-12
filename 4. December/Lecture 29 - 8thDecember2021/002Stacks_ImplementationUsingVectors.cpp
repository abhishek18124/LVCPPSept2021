/*

Implementation of the stack data structure using the vector container.

*/

#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class stack {
	vector<T> v;

public:

	void push(T data) {
		if(size() == v.max_size()) {
			// stack is full
		}
		v.push_back(data);
	}

	void pop() {
		if(empty()) {
			// stack is empty
			return;
		}
		v.pop_back();
	}

	T top() {
		return v.back(); // v[v.size()-1];
	}

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}

};

int main() {

	stack<int> s;

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

