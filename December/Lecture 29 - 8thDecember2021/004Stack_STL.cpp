/*

C++ STL implementation of the stack data structure

*/

#include<iostream>
#include<stack>

using namespace std;

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