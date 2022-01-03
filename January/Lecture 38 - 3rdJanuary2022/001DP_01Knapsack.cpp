/*

You are packing for a vacation on the sea side and you are going to carry only one bag with 
capacity C (1 <= C <= 1000). You also have N (1<= N <= 1000) items that you might want to take 
with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will 
have to choose. For each item you are given its size and its value. You want to maximize the total 
value of all the items you are going to bring. What is this maximum total value?

Example :
	Input : N = 5, W = 4
			weight[] = {1, 2, 3, 2, 2}
			profit[] = {8, 4, 1, 5, 3}
	Output: 12

*/


#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& weight, vector<int>& profit, int i, int w, int N) {

	// base case

	if(i == N) {
		// you've no more object to consider
		return 0;
	}

	if(w == 0) {
		// you've no more capacity left in the knapsack
		return 0;
	}

	// recursive case

	if(weight[i] > w) {
		// exclude the ith object from the knapsack
		return maxProfit(weight, profit, i+1, w, N);
	}

	// for the ith object, we have two options

	// 1. include the ith object in the knapsack
	int X = maxProfit(weight, profit, i+1, w-weight[i], N);

	// 2. exclude the ith object from the knapsack
	int Y = maxProfit(weight, profit, i+1, w, N);

	return max(profit[i]+X, Y);

}

int maxProfitTopDown(vector<int>& weight, vector<int>& profit, 
	                 int i, int w, int N, vector<vector<int>>& dp) {

	// base case

	if(i == N) {
		// you've no more object to consider
		return dp[i][w] = 0;
	}

	if(w == 0) {
		// you've no more capacity left in the knapsack
		return dp[i][w] = 0;
	}

	// lookup

	if(dp[i][w] != -1) {
		return dp[i][w];
	}

	// recursive case

	if(weight[i] > w) {
		// exclude the ith object from the knapsack
		return dp[i][w] = maxProfitTopDown(weight, profit, i+1, w, N, dp);
	}

	// for the ith object, we have two options

	// 1. include the ith object in the knapsack
	int X = maxProfitTopDown(weight, profit, i+1, w-weight[i], N, dp);

	// 2. exclude the ith object from the knapsack
	int Y = maxProfitTopDown(weight, profit, i+1, w, N, dp);

	return dp[i][w] = max(profit[i]+X, Y);

}

int maxProfitBottomUp(vector<int>& weight, vector<int>& profit, int N, int W) {

	vector<vector<int>> dp(N+1, vector<int>(W+1));

	// base case
	for(int i=0; i<=N; i++) {
		dp[i][0] = 0;
	}

	for(int w=0; w<=W; w++) {
		dp[N][w] = 0;
	}

	for(int i=N-1; i>=0; i--) {
		for(int w=1; w<=W; w++) {
			if(weight[i] > w) {
				dp[i][w] = dp[i+1][w];
			} else {
				int X = dp[i+1][w-weight[i]];
				int Y = dp[i+1][w];
				dp[i][w] = max(profit[i]+X, Y);
			}
		}
	}

	return dp[0][W];

}


int main() {

	int N = 5;
	int W = 4;

	vector<int> weight = {1, 2, 3, 2, 2};
	vector<int> profit = {8, 4, 1, 5, 3};

	cout << maxProfit(weight, profit, 0, W, N) << endl;

	vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
	cout << maxProfitTopDown(weight, profit, 0, W, N, dp) << endl;
	cout << maxProfitBottomUp(weight, profit, N, W) << endl;
	
	return 0;
}