/*

Given a stack of integers and an integer element 'x', write a program to 
insert 'x' at the bottom of the stack.

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

    int x = 60;

    print(s);

    insertAtBottom(s, x);

    print(s);

	return 0;
}