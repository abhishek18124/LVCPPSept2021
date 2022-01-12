/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can 
sell the first or the last wine in the row. However, the price of wines increases over time. 

Let the initial profits from the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit from 
the kth wine will be y*p_k. 

Find the maximum profit from all the wines.

Example :
	Input : price[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& price, int i, int j, int y) {

	// base case
	if(i == j) {
		// you're left with a single bottle of wine
		return y * price[i]; // here y is equal to n
	}

	// recursive case

	// in the yth year, you've to decide which bottle of wine you should sell

	// 1. sell the ith wine
	int X = maxProfit(price, i+1, j, y+1);

	// 2. sell the jth wine
	int Y = maxProfit(price, i, j-1, y+1);

	return max(y*price[i] + X, 
		       y*price[j] + Y);

}

int maxProfitBottomUp(vector<int>& price, int n) {

	vector<vector<int>> dp(n, vector<int>(n));

	// base case
	for(int i=0; i<n; i++) {
		dp[i][i] = price[i]*n; // y == n 
	}

	// recursive
	for(int i=n-1; i>=0; i--) {
		for(int j=i+1; j<n; j++) {
			int y = n-(j-i);
			dp[i][j] = max(price[i]*y + dp[i+1][j],
				           price[j]*y + dp[i][j-1]);
		}
	}

	return dp[0][n-1];

}


int main() {

	vector<int> price = {2, 3, 5, 1, 4};
	int n = price.size();

	cout << maxProfit(price, 0, n-1, 1) << endl;
	cout << maxProfitBottomUp(price, n) << endl;

	
	return 0;
}