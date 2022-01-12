/*

You are packing for a vacation on the sea side and you are going to carry only one bag with 
capacity W (1 <= W <= 1000). You also have n (1<= n <= 1000) items that you might want to take 
with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will 
have to choose. For each item you are given its size and its value. You want to maximize the total 
value of all the items you are going to bring. What is this maximum total value?

Example :
	Input : n = 5 W = 4
		    profits = {8, 4, 0, 5, 3}
			weights = {1, 2, 3, 2, 2}
			
	Output: 13

*/



#include<iostream>

using namespace std;

int maxProfit(int* profits, int* weights, int n, int i, int w) {
	// base case
	if(i == n || w == 0) {
		// you've no object to consider or knapsack has no capacity
		return 0;
	}

	// recursive case

	if(weights[i] > w) {
		// you've no option but to exclude the ith object
		return maxProfit(profits, weights, n, i+1, w);
	}

	// you're at the ith object and you've to take a decision

	// 1. include the ith object in the knapsack
	int X = maxProfit(profits, weights, n, i+1, w-weights[i]);

	// 2. exclude the ith object from the knapsack
	int Y = maxProfit(profits, weights, n, i+1, w);

	return max(profits[i]+X, Y);
}

int main() {
	
	int n = 5;
	int W = 4;
	
	int profits[] = {8, 4, 0, 5, 3};
	int weights[] = {1, 2, 3, 2, 2};

	cout << maxProfit(profits, weights, n, 0, W) << endl;
			
	return 0;
}