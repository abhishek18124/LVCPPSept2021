
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example 
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

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

int height(node* root) {
	if(root == NULL) {
		return -1;
	}

	int hL = height(root->left);
	int hR = height(root->right);

	return 1 + max(hL, hR);

}

node* buildTree() {
	int x;
	cin >> x;

	if(x == -1) {
		node* root = NULL;
		// root represents an empty tree
		return root;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right=buildTree();

	return root;
}

bool checkBalance(node* root) {

	// base case
	if(root == NULL) {
		// empty tree is balanced
		return true;
	}

	// recursive case

	// check if the leftSubtree is heightBalanced or not -- ask your friend
	bool X = checkBalance(root->left);

	// check if the rightSubtree is heightBalanced or not -- ask your friend
	bool Y = checkBalance(root->right);

	// check if the root node is heightBalanced or not
	bool Z = abs(height(root->left) - height(root->right)) <= 1 ? true : false;

	return X && Y && Z;

}

class Pair {
public:
	bool isBalanced;
	int height;
};


Pair checkBalanceEfficient(node* root) {

	Pair p;

	// base case
	if(root == NULL) {
		// empty tree is balanced
		p.isBalanced = true;
		p.height = -1;
		return p;
	}

	// recursive case

	// check if the leftSubtree is heightBalanced or not & simulataneously compute its height -- ask your friend
	Pair pL = checkBalanceEfficient(root->left);

	// check if the rightSubtree is heightBalanced or not & simulataneously compute its height -- ask your friend
	Pair pR = checkBalanceEfficient(root->right);

	// check if the root node is heightBalanced or not
	bool Z = abs(pL.height - pR.height) <= 1 ? true : false;

	p.isBalanced = pL.isBalanced && pR.isBalanced && Z;
	p.height = 1 + max(pL.height, pR.height);

	return p;

}


int main() {

	node* root = NULL;
	root = buildTree();
 	checkBalance(root) ? cout << "true" << endl :
 					     cout << "false" << endl;

 	checkBalanceEfficient(root).isBalanced ? cout << "true" << endl :
 					                         cout << "false" << endl;

 	return 0;
 }