/*

Given a stack of integers, write a program to reverse the stack without
use of any supplementary data structure.

*/
#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>& s, int x) {

	// base case
	if(s.empty()) {
		s.push(x);
		return;
	}

	// recursive case

	// 1. remove the element at the top of the stack and store it
	int y = s.top(); 
	s.pop();

	// 2. insert x at the bottom of the resulting stack -- ask your friend
	insertAtBottom(s, x);

	// 3. push the item your removed initally from the stack top back onto the stack
	s.push(y);

} 

void reverse(stack<int>& s) {

	// base case
	if(s.empty()) {
		return;
	}

	// recursive case

	// 1. remove the element at the top of the stack and store it
	int x = s.top(); 
	s.pop();

	// 2. reverse the resulting stack -- ask your friend
	reverse(s);

	// 3. insert the item you've popped initially at the 
	// bottom of the stack
	insertAtBottom(s, x);

}

void print(stack<int> s) {
	while(!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << endl;
}

int main() {

	stack<int> s;

	s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    print(s);

    reverse(s);

    print(s);

	return 0;
}