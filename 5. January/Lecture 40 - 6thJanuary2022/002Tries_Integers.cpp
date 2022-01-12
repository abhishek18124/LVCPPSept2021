/*

Implementation of the TRIE data structure to store non-negative integers.

Assume integer has 32-bit representation.

*/

#include<iostream>

using namespace std;

class node {

	public :

	bool terminal;
	node* left; // indicates if node has a child that represents bit 0
	node* right;// indicates if node has a child that represents bit 1

	node() {
		this->terminal = false;
		this->left = this->right = NULL;
	}

};

class trie {
	node* root;

	public :
		trie() {
			root = new node();
		}

		void insert(int x) {
			node* temp = root;
			for(int i=31; i>=0; i--) {
				int bit = (x>>i)&1;
				if(!bit) {
					// ith bit of x is 0
					if(!temp->left) {
						// temp node does not have a left child
						node* n = new node();
						temp->left = n;
						temp = temp->left;
					} else {
						// temp node has a left child
						temp = temp->left;
					}

				} else {
					// ith bit of x is 1
					if(!temp->right) {
						// temp node does not have a right child
						node* n = new node();
						temp->right = n;
						temp = temp->right;
					} else {
						// temp node has a right child
						temp = temp->right;
					}
				}
			}

			temp->terminal = true;
		}

		bool search(int x) {
			node* temp = root;
			for(int i=31; i>=0; i--) {
				int bit = (x>>i)&1;
				if(!bit) {
					// ith bit is 0
					if(!temp->left) {
						return false;
					}
					temp = temp->left;
				} else {
					// ith bit is 1
					if(!temp->right) {
						return false;
					}
					temp = temp->right;
				}
			}
			return temp->terminal;
		}
};

int main() {

	int A[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(A) / sizeof(int);

	trie t;

	for(int i=0; i<n; i++) {
		t.insert(A[i]);
	}

	int B[] = {1, 2, 5, 10, 25, 0};
	int m = sizeof(B) / sizeof(int);

	for(int i=0; i<m; i++) {
		t.search(B[i]) ? cout << B[i] << " : true " << endl :
		                 cout << B[i] << " : false" << endl;
	}

	return 0;
}