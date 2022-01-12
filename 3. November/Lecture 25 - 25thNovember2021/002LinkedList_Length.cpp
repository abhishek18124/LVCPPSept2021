/*

LinkedList 
----------

Length
 > iterative
 > recursive

*/


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

void insertAtHead(node*& head, int data) {
    // 1. create a new node
    node* n = new node(data); // invokes the parameterised constuctor 
                              // of the node class and constructs a 
                              // node on the heap memory

    // 2. assign the address of the head node to the 
    // next field of the newly created node

    n->next = head; // (*n).next = head;

    // 3. make the newly created node as the new head of the linked list
    // assign to the head pointer the address of the newly created node

    head = n;

}

void printLinkedList(node* head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << endl;
}

int lengthIterative(node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int lengthRecursive(node* head) {
    // base case
    if(head == NULL) {
        // head is NULL means you're trying to calculate the
        // length of an empty linked list
        return 0;
    }
    
    // recursive case
    int x = lengthRecursive(head->next);
    return 1 + x;
}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    cout << "length = " << lengthIterative(head) << endl;
    cout << "length = " << lengthRecursive(head) << endl;

    return 0;
}

