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
    // base case
    if(!head || !head->next) {
        // a linked list which is either empty or contains a single
        // node doesn't have any duplicates so you don't have to 
        // do anything.
        return head;
    }
    
    // recursive case

    if(head->data != head->next->data) {
        // the head of the linked list is not a duplicate node
        // therefore it will be the head of the final ans.

        // ask your friend to remove all the duplicate nodes
        // from the linked list that starts from head->next 
        head->next = removeDuplicates(head->next);
        return head;
    } else {
        // the head of the linked list is a duplicate node therefore
        // skip over all the nodes that contain the data that matches
        // the data of the head node
        while(head->next && head->data == head->next->data) {
            head = head->next;
        }
        // ask your friend to remove all the duplicate nodes
        // from the linked list that starts from head->next 
        return removeDuplicates(head->next);
    }


}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 6);
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


