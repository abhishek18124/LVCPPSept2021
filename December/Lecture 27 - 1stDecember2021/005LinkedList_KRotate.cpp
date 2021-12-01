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

node* kRotate(node* head, int k) {

    // 1. connect the tail of the linked list 
    //    with the head to form a loop

    node* tail = head;
    int n = 1; // to keep track of the length of the linked list
    while(tail->next != NULL) {
        tail = tail->next;
        n++;
    }
    tail->next = head;

    // 2. iterate over the linked list n-(k%n)-1 times
    //    from the head to reach the newTail

    node* newTail = head;
    for(int i=0; i<n-(k%n)-1; i++) {
        newTail = newTail->next;
    }

    node* newHead = newTail->next;

    // 3. break the cycle or the loop by updating the next
    //    field of the newTail

    newTail->next = NULL;

    return newHead;
}


int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    
    printLinkedList(head);

    int k = 7;

    head = kRotate(head, k);

    printLinkedList(head);

    return 0;
}


