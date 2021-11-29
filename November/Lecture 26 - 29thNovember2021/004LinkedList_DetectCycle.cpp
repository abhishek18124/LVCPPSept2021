#include<iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void printLinkedList(node* head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << endl;
}

bool isCyclePresent(node* head) {
    node* slow = head;
    node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            // there exists a cycle
            return true;
        }
    }

    // there does not exist a cycle
    return false;
}

void removeCycle(node* head) {
    node* slow = head;
    node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            // you've reached the meeting point
            break;
        }
    }

    node* prev = head;
    while(prev->next != fast) {
        prev = prev->next;
    }

    // now, prev is at a node just before the meeting point

    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
        prev = prev->next;
    }

    // now, slow and fast are at the intersection point 
    // and prev is at the tail of the linked list

    prev->next = NULL;


}

int main() {

    node* head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);
    head->next->next->next->next->next = new node(60);
    head->next->next->next->next->next->next =  head->next->next->next;

    // printLinkedList(head);
 
    isCyclePresent(head) ? cout << "true" << endl :
                           cout << "false" << endl;

    removeCycle(head);

    isCyclePresent(head) ? cout << "true" << endl :
                           cout << "false" << endl;

    printLinkedList(head);
 
    return 0;
}


