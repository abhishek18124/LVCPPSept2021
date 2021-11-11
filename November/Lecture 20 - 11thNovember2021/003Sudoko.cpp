/*

Sudoku

Given a partially filled 'n x n' grid, the goal is to assign digits from 1 to 9 to the empty cells 
so that every row, column, and subgrid of size '√n x √n'  contains exactly one instance of 
the digits from 1 to 9. 

Assume 'n' is a perfect square, hence there are 'n' subgrids of size '√n x √n' each.


*/

#include<iostream>
#include<cmath>

using namespace std;

bool canPlace(int grid[][9], int n, int i, int j, int digit) {
	for(int k=0; k<n; k++) {
		if(grid[i][k] == digit || grid[k][j] == digit) {
			return false;
		}
	}

	// 'digit' is not present along the same row and the same column
	// of the (i, j)th cell. Now, you've to check whether it is present 
	// in the same subgrid of the (i, j)th cell or not.

	int rn = sqrt(n);
	int sx = i/rn * rn;
	int sy = j/rn * rn;

	for(int x=sx; x<sx+rn; x++) {
		for(int y=sy; y<sy+rn; y++) {
			if(grid[x][y] == digit) {
				return false;
			}
		}
	}

	// digit is also not present in the subgrid of which the (i, j)th
	// cell is part of therefore the digit is a valid candidate for the 
	// (i, j)th cell

	return true;


}

void solveSudoko(int grid[][9], int n, int i, int j) {
	// base case
	if(i == n) {
		// you've filled all the empty cells in all the rows therefore you can stop
		// and print your solution
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	if(j == n) {
		// you've filled all the empty cells in the ith row, so now you can ask your
		// friend to start filling empty cells starting from 0th column of the next row
		solveSudoko(grid, n, i+1, 0);
		return;
	}

	if(grid[i][j] != 0) {
		// you're at the (i, j)th cell which is non-empty, so you can skip it
		// and ask your friend to fill the remaining empty cells starting with
		// the (i, j+1)th cell
		solveSudoko(grid, n, i, j+1);
		return;
	}

	// you're at the (i, j)th cell which is empty, and now you've to assign a 
	// valid digit between 1 to 9 to this cell.

	for(int digit=1; digit <= 9; digit++) {
		if(canPlace(grid, n, i, j, digit)) {
			grid[i][j] = digit;
			solveSudoko(grid, n, i, j+1);
			grid[i][j] = 0; // backtracking
		}
	}	

	return;
}

int main() {

	int n = 9;
	int grid[][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
			         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
			         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
			         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
			         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
			         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
			         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
			         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
			         {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	solveSudoko(grid, n, 0, 0);


	// int grid[][9] = {{7, 8, 0, 4, 0, 0, 1, 2, 0}, 
	// 		         {6, 0, 0, 0, 7, 5, 0, 0, 9}, 
	// 		         {0, 0, 0, 6, 0, 1, 0, 7, 8}, 
	// 		         {0, 0, 7, 0, 4, 0, 2, 6, 0}, 
	// 		         {0, 0, 1, 0, 5, 0, 9, 3, 0}, 
	// 		         {9, 0, 4, 0, 6, 0, 0, 0, 5}, 
	// 		         {0, 7, 0, 3, 0, 0, 0, 1, 2}, 
	// 		         {1, 2, 0, 0, 0, 7, 4, 0, 0}, 
	// 		         {0, 4, 9, 2, 0, 6, 0, 0, 7}};

	
	return 0;
}

