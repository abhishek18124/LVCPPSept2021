/*

N Queens Problem

The problem is to place 'n' queens on an 'n x n' chessboard, so that no two queens are attacking 
each other, this means that no two queens are in the same row, the same column, or the same diagonal.

Example 
	Input : N = 4
	Output: 
			_ Q _ _	     _ _ Q _
	        _ _ _ Q      Q _ _ _ 
	        Q _ _ _      _ _ _ Q
	        _ _ Q _      _ Q _ _ 

	        [1, 3, 0, 2] [2, 0, 3, 1]

Constraint:
	1<=n<=10	        

*/

#include<iostream>

using namespace std;

void nQueens(int n, int* QPos, int r) {
	// base case
	if(r == n) {
		// you've placed all the Qs [Q0....Qn-1], so you can stop
		// and print the solution you've built.
		// for(int i=0; i<n; i++) {
		// 	cout << QPos[i] << " ";
		// }
		// cout << endl;

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(QPos[i] == j) {
					cout << 'Q' << " ";
				} else {
					cout << '-' << " ";
				}
			}
			cout << endl;
		}
		cout << endl;

		return;
	}


	// recursive case

	// You've to place Qr in column 'j' of row 'r'
	// where 0<=j<n such that it doesn't attach any 
	// previously placed queen Qi where 0<=i<=r-1

	for(int j=0; j<n; j++) {
		bool canPlace = true; // I am assuming you can place Qr at column j

		for(int i=0; i<=r-1; i++) {
			if(QPos[i] == j || QPos[i] == j-(r-i) || QPos[i] == j+(r-i)) {
				canPlace = false;
				break;
			}
		}

		if(canPlace) {
			QPos[r] = j; // you're overriding the previous valid position 
						 // for Qr therefore you're implicitly backtracking
			nQueens(n, QPos, r+1);
		}
	}
}

int main() {

	int n = 4;
	int QPos[10];

	nQueens(n, QPos, 0);

	return 0;
}