/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

int findMinimum(node* root) {

	if(root == NULL) {
		// leftMost node in an empty tree is also NULL
		return INT_MAX;
	}

	while(root->left != NULL) {
		root = root->left;
	}

	return root->data;
}

int findMaximum(node* root) {

	if(root == NULL) {
		// rightMost node in an empty tree is also NULL
		return INT_MIN;
	}

	while(root->right != NULL) {
		root = root->right;
	}

	return root->data;
}


bool checkBST(node* root) {

	// base case

	if(root == NULL) {
		// empty tree is a BST
		return true;
	}

	// recursive case

	// check if the leftSubtree is a BST -- ask your friend
	bool X = checkBST(root->left);

	// check if the rightSubtree is a BST -- ask your friend
	bool Y = checkBST(root->right);

	// check the BST property at the root node

	bool Z = root->data > findMaximum(root->left) && 
	         root->data < findMinimum(root->right) ? true : false;

    return X && Y && Z;

}

class Triple {

public:

	bool isBST;
	int minData;
	int maxData;

};

Triple checkBSTEfficient(node* root) {

	Triple t;

	// base case

	if(root == NULL) {
		// empty tree is a BST
		t.isBST = true;
		t.minData = INT_MAX;
		t.maxData = INT_MIN;
		return t;
	}

	// recursive case

	// check if the leftSubtree is a BST & simulataneously compute its minimum & maximum values -- ask your friend
	Triple tL = checkBSTEfficient(root->left);

	// check if the rightSubtree is a BST & simulataneously compute its minimum & maximum values -- ask your friend
	Triple tR = checkBSTEfficient(root->right);

	// check the BST property at the root node

	bool Z = root->data > tL.maxData && 
	         root->data < tR.minData ? true : false;

	t.isBST = tL.isBST && tR.isBST && Z;
	t.minData = min(tL.minData, root->data);
	t.maxData = max(tR.maxData, root->data);

	return t;

}

bool checkBSTEfficientRange(node* root, int lb, int ub) {

	if(root == NULL) {
		// empty tree is a BST
		return true;
	}

	if((root->data>lb && root->data<ub) &&
	   checkBSTEfficientRange(root->left, lb, root->data) && 
	   checkBSTEfficientRange(root->right, root->data, ub)) {
		return true;
	}

	return false;

}

int main() {

	node* root = new node(10);
	
	root->left = new node(5);
	root->left->left  = new node(3);
	root->left->right = new node(7);

	root->right = new node(15);
	root->right->left  = new node(13);
	root->right->right = new node(0);

	checkBST(root) ? cout << "true" << endl :
				     cout << "false" << endl;

	checkBSTEfficient(root).isBST ? cout << "true" << endl :
				                    cout << "false" << endl;

	checkBSTEfficientRange(root, INT_MIN, INT_MAX) ? cout << "true" << endl :
				                                     cout << "false" << endl;
			                    

	return 0;
}