/*

LinkedList 
----------

Insert
 > at the head 
 > at the tail 
 > at an index 

Delete 
 > from the head
 > from the tail
 > from an index

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

// node* insertAtHead(node* head, int data) {
//     // 1. create a new node
//     node* n = new node(data); // invokes the parameterised constuctor 
//                               // of the node class and constructs a 
//                               // node on the heap memory

//     // 2. assign the address of the head node to the 
//     // next field of the newly created node

//     n->next = head; // (*n).next = head;

//     // 3. make the newly created node as the new head of the linked list
//     // assign to the head pointer the address of the newly created node

//     head = n;

//     return head;


// }

void printLinkedList(node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* getTail(node* head) {
    while(head->next != NULL) {
        head = head->next;
    }
    return head;
}

void insertAtTail(node*& head, int data) {
    if(head == NULL) {
        insertAtHead(head, data);
        return;
    }

    // 1. fetch the pointer to the tail node
    node* tail = getTail(head);

    // 2. create a new node 
    node* n = new node(data);

    // 3. assign to the next pointer to the tail node
    // the address of the newly created node
    tail->next = n;
}

node* getNode(node* head, int index) {
    int j = 0;
    while(j < index && head != NULL) {
        head = head->next;
        j++;
    }
    return head;
}

void insertAtIndex(node*& head, int data, int i) {
    if(i == 0) {
        insertAtHead(head, data);
        return;
    }

    // 1. fetch the pointer to the node at index i-1
    node* prev = getNode(head, i-1);

    if(prev == NULL) {
        // index specified by the user exceed 
        // the length of the linked list

        insertAtTail(head, data); // depends on the the question
                                  // what needs to be done in case
                                  // i exceeds the length of the 
                                  // linked list
        return;
    }

    // 2. create a new node
    node* n = new node(data);

    // 3. assign to the next pointer of the newly created
    // node the address of the node that comes after the
    // previous node
    n->next = prev->next;

    // 4. assign to the next pointer of the previous node
    // the address of the newly created node
    prev->next = n;
}

void deleteFromHead(node*& head) {
    if(head == NULL) {
        // the linked list is empty
        return;
    }

    // 1. create a temporary pointer to point the head
    // of the linked list

    node* temp = head;

    // 2. update the address of the head pointer to point
    // to the node that comes after the head node

    head = head->next;

    // 3. release the memory allocated for the temporary
    // node.

    delete temp;
}

void deleteFromTail(node*& head) {
    if(head == NULL) {
        // linked list is empty
        return;
    }

    if(head->next == NULL) {
        // linked list contains only a single node
        deleteFromHead(head);
        return;
    }

    node* tail = head;
    node* prev = NULL;

    while(tail->next != NULL) {
        prev = tail;
        tail = tail->next;
    }

    prev->next = NULL;
    delete tail;
}

void deleteFromIndex(node*& head, int i) {
    if(head == NULL) {
        // given linked list is emtpy
        return;
    }

    if(i == 0) {
        // deleting at index 0 is equivalent to 
        // deleting from the head of the linked list
        deleteFromHead(head);
        return;
    }

    node* cur = getNode(head, i);
    if(cur == NULL) {
        // you're trying to delete a node at an index 
        // which exceed the length of the length 

        deleteFromTail(head); // depends on the question
        return;
    }
    
    node* prev= getNode(head, i-1);
    prev->next = cur->next;
    delete cur;
}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 5);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    // head = insertAtHead(head, 5);
    // head = insertAtHead(head, 3);
    // head = insertAtHead(head, 2);
    // head = insertAtHead(head, 1);

    insertAtTail(head, 6);

    printLinkedList(head);

    insertAtTail(head, 7);

    printLinkedList(head);

    insertAtIndex(head, 4, 3);

    printLinkedList(head);

    insertAtIndex(head, 0, 0);

    printLinkedList(head);

    insertAtIndex(head, 9, 10);

    printLinkedList(head);

    insertAtIndex(head, 8, 8);

    printLinkedList(head);

    deleteFromHead(head);

    printLinkedList(head);

    deleteFromTail(head);

    printLinkedList(head);

    deleteFromTail(head);

    printLinkedList(head);

    deleteFromIndex(head, 3);

    printLinkedList(head);

    deleteFromIndex(head, 0);

    printLinkedList(head);

    deleteFromIndex(head, 10);

    printLinkedList(head);

    return 0;
}

