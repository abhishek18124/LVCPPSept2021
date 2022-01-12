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

node* reverseIterative(node* head) {

    node* cur = head;
    node* prev= NULL;

    while(cur != NULL) {
        node* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    return prev;
}

node* reverseRecursive(node* head) {

    // base case

    // if(head == NULL || head->next == NULL) {
    //     return head;
    // }

     if(!head || !head->next) {
        return head;
    }

    // recursive case

    // 1. ask your friend to reverse the linked list
    // that starts from the node that comes after the
    // head node of the given linked list

    node* headFromMyFriend = reverseRecursive(head->next);

    // 2. assign to the next pointer of the node that
    // comes after the head node the address of the 
    // head node

    head->next->next = head;

    // 3. assign to the next pointer of the head node
    // the NULL address

    head->next = NULL;

    // 4. return the head of the reversed linked list
    // which is the head you get back from your friend

    return headFromMyFriend;

}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    printLinkedList(head);

    head = reverseIterative(head);

    printLinkedList(head);

    head = reverseRecursive(head);

    printLinkedList(head);

    return 0;
}


