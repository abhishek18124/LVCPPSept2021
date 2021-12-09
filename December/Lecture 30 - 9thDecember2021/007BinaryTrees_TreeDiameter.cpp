/*

given the pre-order traversal of a binary tree, design a recursive algorithm 
to compute its diameter

	  diameter of a binary tree is the length of the longest path between any 
	  two nodes in the binary tree.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 5

          Input  : 10 20 30 50 -1 -1 -1 40 -1 60 -1 -1 70 -1 -1
          Output : 4
          
          Input  : 10 20 -1 -1 30 40 60 -1 -1 -1 50 -1 70 -1 -1
          Output : 4
          
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
		// x == -1 presents an empty tree
		return NULL;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right= buildTree();

	return root;
}

int height(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		return -1;
	}

	int hL = height(root->left);
	int hR = height(root->right);
	return 1 + max(hL, hR);
}

int diameter(node* root) {
	// base case
	if(root == NULL) {
		// you are trying to compute the diamter of an empty tree
		return 0;
	}

	// recursive case

	// compute the diameter of the left subtree -- ask your friend
	int X = diameter(root->left);

	// compute the diamter of the right subtree -- ask your friend
	int Y = diameter(root->right);

	// compute the length of the longest path between any two nodes that passes
	// through the root node

	int Z = height(root->left) + 2 + height(root->right);

	return max(X, max(Y, Z)); 

}

class Pair {
public:
	int diameter;
	int height;
};


Pair diameterEfficient(node* root) {
	Pair p;

	// base case
	if(root == NULL) {
		// you are trying to compute the diamter & height of an empty tree
		p.diameter = 0;
		p.height = -1;
		return p;
	}

	// recursive case

	// compute the diameter & height of the left subtree -- ask your friend
	Pair pL = diameterEfficient(root->left);

	// compute the diameter & height of the right subtree -- ask your friend
	Pair pR = diameterEfficient(root->right);

	// compute the length of the longest path between any two nodes that passes
	// through the root node

	int Z = pL.height + 2 + pR.height;

	p.height = 1 + max(pL.height, pR.height);
	p.diameter = max(pL.diameter, max(pR.diameter, Z));

	return p; 

}


int main() {

	node* root = NULL;
	root = buildTree();
	// cout << "diamter : " << diameter(root) << endl;
	Pair p = diameterEfficient(root);
	cout << "diameter : " << p.diameter << endl;

	return 0;
}

