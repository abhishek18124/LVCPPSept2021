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


int lengthIterative(node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

node* bubbleSort(node* head) {

    int i = 1;
    int n = lengthIterative(head);
    while(i < n) {
        int j = 0;
        node* prev = NULL;
        node* cur = head; // node @ jth index
        while(j < n-i) {
            node* tmp = cur->next; // node @ (j+1)th index
            if(cur->data > tmp->data) {
                // swap cur<->tmp
                cur->next = tmp->next;
                tmp->next = cur;
                if(prev == NULL) {
                    // you're trying to swap the node @ 0th index 
                    // with the node @ 1st index therefore your
                    // your head must change to tmp node.
                    head = tmp;
                } else {
                    prev->next= tmp;
                }
                prev = tmp;
            } else {
                // donot swap cur<->tmp
                prev = cur;
                cur = tmp;
            }
            j++;
        }
        i++;
    }

    return head;

}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    insertAtHead(head, 60);

    printLinkedList(head);

    head = bubbleSort(head);

    printLinkedList(head);

    return 0;
}


