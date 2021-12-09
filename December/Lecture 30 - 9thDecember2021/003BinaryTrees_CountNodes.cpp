/*

Given the pre-order traversal of a binary tree, design a recursive algorithm to 
compute the number of nodes inside the binary tree

Example : Input  :10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 7
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

int countNodes(node* root) {

	// base case
	if(root == NULL) {
		// you're counting the number of nodes in an empty tree
		return 0;
	}

	// recursive case
	
	// count the number of nodes in the left subtree -- ask your friend
	int X = countNodes(root->left);

	// count the number of nodes in the right subtree -- ask your friend
	int Y = countNodes(root->right);

	return X+1+Y;

}

int main() {

	node* root = NULL;
	root = buildTree();
	cout << countNodes(root) << endl;

	return 0;
}

