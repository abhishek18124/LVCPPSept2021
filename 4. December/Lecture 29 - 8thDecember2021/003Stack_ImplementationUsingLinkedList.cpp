/*

Implementation of the stack data structure using the linked list data structure.

*/

#include<iostream>

using namespace std;

template <typename T>
class node {
public:
    T data;
    node<T>* next;

    node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class forward_list {
    node<T>* head;
    int count;

public:

    forward_list() {
        head = NULL;
        count = 0;
    }

    void push_front(T data) {
        node<T>* n = new node<T>(data);
        n->next = head;
        head = n;
        count++;
    }

    void pop_front() {
        if(!head) return;
        node<T>* tmp = head;
        head = head->next;
        delete tmp;
        count--;
    }

    T front() {
        return head->data;
    }

    int size() {
        return count;
    }

    bool empty() {
        return head == NULL; 
    }
};

template <typename T>
class stack {
    forward_list<T> l;
public:

    void push(T data) {
        l.push_front(data);
    }

    void pop() {
        if(empty()) {
            // stack is empty
            return;
        }
        l.pop_front();
    }

    bool empty() {
        return l.empty();
    }

    int size() {
        return l.size();
    }

    T top() {
        return l.front();
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


