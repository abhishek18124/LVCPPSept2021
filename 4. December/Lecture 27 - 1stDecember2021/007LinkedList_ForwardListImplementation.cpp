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
        return head == NULL; // or count == 0
    }

    void traverse() {
        node<T>* tmp = head;
        while(tmp != NULL) {
            cout << tmp->data;
            tmp = tmp->next;
            if(tmp != NULL) cout << "->";
        }
        cout << endl;
    }

};

int main() {

    forward_list<char> l;

    l.push_front('a');
    l.push_front('b');
    l.push_front('c');
    l.push_front('d');
    l.push_front('e');

    cout << "size : " << l.size() << endl;

    l.traverse();

    l.pop_front();

    cout << "size : " << l.size() << endl;

    l.traverse();

    l.empty() ? cout << "true" << endl : cout << "false" << endl;

    cout << "head->data = " << l.front() << endl;

    return 0;
}