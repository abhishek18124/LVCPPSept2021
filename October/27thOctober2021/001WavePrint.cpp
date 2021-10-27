/*

Given an integer matrix 'mat' of dimensions m x n, write a program that prints
the matrix in wave form.

Example :
	Input : mat[][] = [[1, 2, 3],
					   [4, 5, 6],
					   [7, 8, 9]]

	Output : 1 4 7 8 5 2 3 6 9

*/

#include<iostream>

using namespace std;

int main() {

	int mat[][3] = {{1, 2, 3},
					{4, 5, 6},
					{7, 8, 9}};

	int m = 3;
	int n = 3;

	for(int j=0; j<n; j++) {
		if(j%2 == 0) {
			// jth column in an even column
			for(int i=0; i<m; i++) {
				cout << mat[i][j] << " ";
			}
		} else {
			// jth column is an odd column
			for(int i=m-1; i>=0; i--) {
				cout << mat[i][j] << " ";
			}
		}
	}

	cout << endl;

	
	return 0;
}