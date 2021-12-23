/*

	given the pre-order traversal of a binary tree, output its vertical order traversal.

	Example 
		Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
		Output: 40
		        20 70
		        10 50
		        30
		        60
*/

#include<iostream>
#include<vector>
#include<map>

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
		// root represents an empty tree
		return root;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right=buildTree();

	return root;
}


void verticalOrder(node* root, int d, map<int, vector<int>>& m) {
	// base case
	if(!root) {
		return;
	}

	// recursive case
	
	m[d].push_back(root->data);
	verticalOrder(root->left,  d-1, m);
	verticalOrder(root->right, d+1, m);

}

int main() {

	node* root = NULL;
	root = buildTree();

	map<int, vector<int>> m;
	verticalOrder(root, 0, m);

	for(auto p : m) {
		// cout << p.first << " ";
		for(auto x : p.second) {
			cout << x << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}

