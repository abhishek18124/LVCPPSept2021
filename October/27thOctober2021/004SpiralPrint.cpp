/*

Given an integer matrix 'mat' of dimensions m x n, write a function that prints
the matrix in spiral form.

Example :
	Input : mat[][] = [[1,  2,  3,  4],
					   [5,  6,  7,  8],
					   [9,  10, 11, 12],
					   [13, 14, 15, 16]]

	Output : 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

	Input : mat[][] = [[1,  2,  3,  4],
					   [5,  6,  7,  8],
					   [9,  10, 11, 12]]

	Output : 1 2 3 4 8 12 11 10 9 5 6 7

Constraints :
	
	1 <= m, n <= 10

*/

#include<iostream>

using namespace std;

int main() {
	
	int mat[][4] = {{1,  2,  3,  4},
					{5,  6,  7,  8},
					{9,  10, 11, 12}};

	int m = 3;
	int n = 4;

	int sr = 0;
	int sc = 0;
	int er = m-1;
	int ec = n-1;

	while(sr <= er and sc <= ec) {
		// print the sr by it. from sc to ec
		for(int col=sc; col<=ec; col++) {
			cout << mat[sr][col] << " ";
		}
		sr++;

		// print the ec by it. from sr to er
		for(int row=sr; row<=er; row++) {
			cout << mat[row][ec] << " ";
		}
		ec--;

		// print the er by it. from ec to sc
		if(sr <= er) {
			for(int col=ec; col>=sc; col--) {
				cout << mat[er][col] << " ";
			}
			er--;
		}

		// print the sc by it. from er to sr
		if(sc <= ec) {
			for(int row=er; row>=sr; row--) {
				cout << mat[row][sc] << " ";
			}
			sc++;
		}
	}

	cout << endl;

	return 0;
}