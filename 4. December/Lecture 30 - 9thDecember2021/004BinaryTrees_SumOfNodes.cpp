/*

Given the pre-order traversal of a binary tree, design a recursive algorithm to 
compute the sum of nodes inside the binary tree

Example : Input  :10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 280
*/

#include<iostream>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

node* buildTree() {
	int x;
	cin >> x;

	if(x == -1) {
		node* root = NULL;
		// root represent an empty tree
		return root;
	}

	node* root  = new node(x);
	root->left  = buildTree();
	root->right = buildTree();

	return root;

}

int sumOfNodes(node* root) {
	// base case
	if(root == NULL) {
		// you're trying to compute the sum of an empty tree
		return 0;
	}
	
	// recursive case

	// 1. compute the sum of the left subtree  -- ask your friend
	int X = sumOfNodes(root->left);

	// 2. compute the sum of the right subtree -- ask your friend
	int Y = sumOfNodes(root->right);

	return X + Y + root->data;

}

int main() {

	node* root = NULL;
	root = buildTree();
	cout << "sum : " << sumOfNodes(root) << endl;

	return 0;
}

