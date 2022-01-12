/*

Given an integer matrix 'mat' of dimensions m x n and an integer 't', write a program 
to search for 't' in 'mat'. 

If 't' is present in the matrix return its coordinates otherwise return (-1, -1).

Example :
	Input : mat[][] = [[1,  2,  3,  4],
					   [5,  6,  7,  8],
					   [9,  10, 11, 12],
					   [13, 14, 15, 16]]

			t = 10

	Output: (2, 1)

Constraints :
	
	1 <= m, n <= 10

*/

#include<iostream>

using namespace std;

pair<int, int> matrixSearch(int mat[][10], int m, int n, int t) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(mat[i][j] == t) {
				return {i, j}; // make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

int main() {

	int mat[10][10];

	int m;
	cout << "Enter the number of rows : ";
	cin >> m;

	int n;
	cout << "Enter the number of cols : ";
	cin >> n;

	// read values into matrix row-wise
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}

	int t;
	cout << "Enter the target : ";
	cin >> t;

	pair<int, int> p = matrixSearch(mat, m, n, t);
	cout << "{" << p.first << ", " << p.second << "}" << endl;

	return 0;
}