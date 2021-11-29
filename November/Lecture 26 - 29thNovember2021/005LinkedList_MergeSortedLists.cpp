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

node* merge(node* head1, node* head2) {

    if(head1 == NULL) {
        // you are trying to merge the first linked list
        // represented by head1 which is empty with head2 
        // which may or maynot be empty. 

        // In any case, the merged linked list will correspond 
        // to the second linked list

        return head2;
    }

    if(head2 == NULL) {
        // you are trying to merge the second linked list
        // represented by head2 which is empty with head1 
        // which is not empty therefore the merged linked 
        // list will correspond to the first linked list
       
        return head1;
    }

    node* head = NULL;

    if(head1->data < head2->data) {
        // head of the first linked list will be the head of the
        // merged linked list
        head = head1;
        node* headFromMyFriend = merge(head1->next, head2);
        head->next = headFromMyFriend;
    } else {
        // head of the second linked list will be the head of the
        // merged linked list
        head = head2;
        node* headFromMyFriend = merge(head1, head2->next);
        head->next = headFromMyFriend;
    }

    return head;
}

int main() {

    node* head1 = NULL; // initially, my linked list is empty

    insertAtHead(head1, 50);
    insertAtHead(head1, 30);
    insertAtHead(head1, 10);

    printLinkedList(head1);

    node* head2 = NULL; // initially, my linked list is empty

    insertAtHead(head2, 60);
    insertAtHead(head2, 40);
    insertAtHead(head2, 20);

    printLinkedList(head2);

    node* head = merge(head1, head2);

    printLinkedList(head);
  
    return 0;
}


