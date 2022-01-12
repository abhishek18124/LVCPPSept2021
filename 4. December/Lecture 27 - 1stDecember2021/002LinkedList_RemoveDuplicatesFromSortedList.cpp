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


node* removeDuplicates(node* head) {
    if(!head) {
        // linked list is empty
        return head;
    }

    node* tail= head;
    node* cur = head->next;
    while(cur != NULL) { // or while(cur) {
        if(cur->data != tail->data) {
            // cur node contains data that we are seeing for
            // the first time therefore track the cur node
            tail->next = cur;
            tail = cur;
        }
        cur = cur->next;
    }
    // ensure the next field of tail node of the final
    // ans. contains NULL address
    tail->next = NULL;
    return head;
}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 5);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    head = removeDuplicates(head); 

    printLinkedList(head);

    return 0;
}


