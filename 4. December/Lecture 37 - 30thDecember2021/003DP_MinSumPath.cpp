/*

Given a m x n grid filled with non-negative numbers, find a path from (0, 0) to 
(m-1, n-1), which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example : 
	Input: grid = [[1,3,1],
	               [1,5,1],
	               [4,2,1]]

	Output: 7
	Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Constraints :
	1 <= m, n <= 200
	0 <= grid[i][j] <= 100

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minSum(vector<vector<int>>& grid, int i, int j) {

	// base case
	if(i == 0 && j == 0) {
		return grid[0][0];
	}

	// additional base case that allows you to go outside the grid

	// if(i < 0 || j < 0) {
	// 	return INT_MAX;
	// }

	// recursive case
	if(i == 0) {
		// you can reach the (i, j)th cell from the left
		return grid[i][j] + minSum(grid, i, j-1);
	}

	if(j == 0) {
		// you can reach the (i, j)th cell from the top
		return grid[i][j] + minSum(grid, i-1, j);
	}

	// you can reach the (i, j)th cell from top or left

	int x = minSum(grid, i-1, j);
	int y = minSum(grid, i, j-1);

	return grid[i][j] + min(x, y);

}

int minSumTopDown(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {

	// base case
	if(i == 0 && j == 0) {
		return dp[i][j] = grid[0][0];
	}

	// lookup
	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	// recursive case
	if(i == 0) {
		// you can reach the (i, j)th cell from the left
		return dp[i][j] = grid[i][j] + minSumTopDown(grid, i, j-1, dp);
	}

	if(j == 0) {
		// you can reach the (i, j)th cell from the top
		return dp[i][j] = grid[i][j] + minSumTopDown(grid, i-1, j, dp);
	}

	// you can reach the (i, j)th cell from top or left

	int x = minSumTopDown(grid, i-1, j, dp);
	int y = minSumTopDown(grid, i, j-1, dp);

	return dp[i][j] = grid[i][j] + min(x, y);

}

int minSumBottomUp(vector<vector<int>>& grid) {
 	int m = grid.size();
   	int n = grid[0].size();

   	vector<vector<int>> dp(m, vector<int>(n));

   	for(int i=0; i<m; i++) {
   		for(int j=0; j<n; j++) {
   			if(i == 0 && j == 0) {
   				dp[i][j] = grid[i][j];
   			} else if(i == 0) {
   				dp[i][j] = grid[i][j] + dp[i][j-1];
   			} else if(j == 0) {
   				dp[i][j] = grid[i][j] + dp[i-1][j];
   			} else {
				dp[i][j] = grid[i][j] + min(dp[i-1][j], 
					                        dp[i][j-1]);
   			}
   		}
   	}

   	return dp[m-1][n-1];
}

int main() {

	vector<vector<int>> grid = {{1, 3, 1},
   								{1, 5, 1},
   								{4, 2, 1}};

   	int m = grid.size();
   	int n = grid[0].size();

   	cout << minSum(grid, m-1, n-1) << endl;

   	vector<vector<int>> dp(m, vector<int>(n, -1));
   	cout << minSumTopDown(grid, m-1, n-1, dp) << endl;
   	cout << minSumBottomUp(grid) << endl;

	return 0;
}






