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

node* kthNodeFromLast(node* head, int k) {
    if(!head) return head;

    node* slow = head;
    node* fast = head;

    while(k-- && fast) {
        fast = fast->next;
    }


    while(fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;

}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    int k = 6;

    node* kth = kthNodeFromLast(head, k);

    if(kth != NULL) {
        cout << "kth node from last : " << kth->data << endl;
    } else {
        cout << "the linked list is empty !" << endl;
    }

    return 0;
}


