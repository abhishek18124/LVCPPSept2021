/*

LinkedList 
----------

Search
 > iterative
 > recursive
 
*/


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

bool searchIterative(node* head, int t) {
    while(head != NULL) {
        if(head->data == t) {
            return true;
        }
        head = head->next;
    }
    return false;
}

bool searchRecursive(node* head, int t) {
    if(head == NULL) {
        // you're trying to search for the target inside an 
        // empty linked list
        return false;
    }

    // recursive case
    if(head->data == t) {
        // you've found the target in the given linked list
        return true;
    }

    // ask your friend to search for the target in the linked
    // list that starts from the node that comes after the head
    // node of the given linked list

    bool ansFromMyFriend = searchRecursive(head->next, t);
    return ansFromMyFriend;

}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    int t = 3;

    searchIterative(head, t) ? cout << "true" << endl : cout << "false" << endl;
    searchRecursive(head, t) ? cout << "true" << endl : cout << "false" << endl;

    return 0;
}

