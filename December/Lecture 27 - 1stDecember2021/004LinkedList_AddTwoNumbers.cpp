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

node* add(node* head1, node* head2) {
    node* head = NULL;
    int c_val = 0;
    while(head1 != NULL && head2 != NULL) {

        int sum = head1->data + head2->data + c_val;
        c_val = sum/10;
        
        node* n = new node(sum%10);
        n->next = head;
        head = n;

        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1 != NULL) {
        // insert the remaining digits of the first no. to 
        // the final answer

        int sum = head1->data + c_val;
        c_val = sum/10;
        
        node* n = new node(sum%10);
        n->next = head;
        head = n;

        head1 = head1->next;

    }

    while(head2 != NULL) {
        // insert the remaining digits of the second no. to 
        // the final answer

        int sum = head2->data + c_val;
        c_val = sum/10;
        
        node* n = new node(sum%10);
        n->next = head;
        head = n;

        head2 = head2->next;

    }


    if(c_val) {
        node* n = new node(c_val);
        n->next = head;
        head = n;
    }

    return head;

}

node* addCompact(node* head1, node* head2) {
    node* head = NULL;
    int c_val = 0;
    while(head1 || head2 || c_val) {

        int d1 = head1 ? head1->data : 0;
        int d2 = head2 ? head2->data : 0;

        int sum = d1 + d2 + c_val;
        c_val = sum/10;
        
        node* n = new node(sum%10);
        n->next = head;
        head = n;

        head1 = head1 ? head1->next : NULL;
        head2 = head2 ? head2->next : NULL;
    }

    return head;

}


int main() {

    node* head1 = NULL; // initially, my linked list is empty

    insertAtHead(head1, 9);
    insertAtHead(head1, 9);
    insertAtHead(head1, 7);
    insertAtHead(head1, 3);
    
    printLinkedList(head1);

    node* head2 = NULL;

    insertAtHead(head2, 4);
    insertAtHead(head2, 5);
    insertAtHead(head2, 6);
    
    printLinkedList(head2);

    node* head = add(head1, head2); 

    printLinkedList(head);

    head = addCompact(head1, head2);

    printLinkedList(head);

    return 0;
}


