/*

Given an array of non-negative integers of size n, find the maximum possible XOR between 
any two numbers present in the array.

Example: 
	Input : A[] = {25, 10, 2, 8, 5, 3} 
	Output: 28 
	Explaination: The maximum result is 5 ^ 25 = 28 
	
	Input: A[] = {1, 2, 3, 4, 5, 6, 7} 
	Output: 7 
	Explaination: The maximum result is 1 ^ 6 = 7 

*/

#include<iostream>
#include<climits>

using namespace std;

class node {
public:
	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1
	
	node() {
		this->left = NULL;
		this->right= NULL;
	}
};

class trie {
	node* root;
public:
	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for(int i=31; i>=0; i--) {
			int bit = (1<<i)&n;
			if(!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if(!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if(!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	// return the maximum possible xor involving n
	int helper(int n) {
		node* temp = root;
		int XOR = 0; // to store the maximum possible XOR involving n
		int x_k = 0; // to store the integer with which we get maximum possible XOR involving A[i] i.e n
		for(int i=31; i>=0; i--) {
			int bit = (1<<i)&n;
			if(!bit) {
				// ith bit of n is 0
				if(temp->right) {
					// temp node has a right child, therefore ith bit of XOR can be 1
					XOR += (1<<i);
					x_k += (1<<i);
					temp = temp->right;
				} else {
					// temp node doesn't have a right child, threfore ith bit of XOR is 0
					temp = temp->left;
				}
			} else {
				// ith bit of n is 1
				if(temp->left) {
					// temp node has a left child, therefore the ith bit of XOR can be 1
					XOR += (1<<i);
					temp = temp->left;
				} else {
					// temp node doesn't have a left child, therefore ith bit of XOR is 0
					temp = temp->right;
					x_k += (1<<i);
				}
			}
		}

		cout << "maxXOR(" << n << ", " << x_k << ") : " << XOR << endl;

		return XOR;
	}

	int maximumXOR(int A[], int n) {
		int finalAns = 0;
		for(int i=0; i<n; i++) {
			finalAns = max(finalAns, helper(A[i]));
		}
		return finalAns;
	}

};

int main() {

	int A[] = {10, 2, 8, 5, 3};
	int n = sizeof(A) / sizeof(int);

	trie t;

	for(int i=0; i<n; i++) {
		t.insert(A[i]);
	}

	cout << t.maximumXOR(A, n) << endl;

	return 0;
}



