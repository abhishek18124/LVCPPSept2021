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

node* kReverse(node* head, int k) {

    // if(head == NULL) {
    //     // the given linked list is empty
    //     return head;
    // }

    if(!head) {
        return head;
    }

    // 1. Reverse the first k nodes of the linked 
   
    // int i = 0;
    int i = k;
    node* cur = head;
    node* prev = NULL;

    // while(cur != NULL && i < k) {
    while(cur && i--) {
        node* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
        // i++;
    }

    // 2. Ask your friend to k-Reverse the linked list composed
    // of the last n-k nodes that starts with cur node
    node* headFromMyFriend = kReverse(cur, k);
    head->next = headFromMyFriend;

    return prev;


}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    int k = 3;

    head = kReverse(head, k);

    printLinkedList(head);

    return 0;
}


