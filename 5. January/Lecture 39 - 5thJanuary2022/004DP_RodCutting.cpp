/*

Example :
	
	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [1,  5,  8,  9,  10, 17, 17, 20]
	Output : 22

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [3,  5,  8,  9, 10, 17, 17, 20]
	Output : 24

	
*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxProfitBottomUp(vector<int>& prices, int n) {
	vector<int> dp(n+1);

	// base case
	dp[0] = 0;

	// recursive case
	for(int i=1; i<=n; i++) {
		int ans = INT_MIN;
		for(int j=1; j<=n; j++) {
			if(i-j >= 0) {
				int pj = prices[j-1];
				ans = max(ans, pj + dp[i-j]);
			}
		}
		dp[i] = ans;
	}

	return dp[n];
}

int main() {

	vector<int> prices = {3,  5,  8,  9, 10, 17, 17, 20};
	int n = prices.size();

	cout << maxProfitBottomUp(prices, n) << endl;

	return 0;
}