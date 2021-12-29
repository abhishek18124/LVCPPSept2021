/*

Given a number n, count the minimum steps to reduce n to 1 such that at each 
step you may

	reduce n to n/2 if n is divisible by 2
	or reduce n to n/3 if n is divisible by 3
	or reduce n to n-1 by decrementing n by 1

Example :
	Input : n = 10
	Output : 3

	Input : 6
	Output : 2

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minStepsToOne(int n) {

	// base case
	if(n == 1) {
		return 0;
	}

	// recursive case

	int a = INT_MAX;
	if(n%2 == 0) {
		// ask your friend to find minSteps reqd. to reduce n/2 to 1
		a = minStepsToOne(n/2);
	}

	int b = INT_MAX;
	if(n%3 == 0) {
		// ask your friend to find minSteps reqd. to reduce n/3 to 1
		b = minStepsToOne(n/3);
	}

	int c = minStepsToOne(n-1);

	return 1 + min(a, min(b, c));

}

int minStepsToOneTopDown(int n, vector<int>& dp) {

	// base case
	if(n == 1) {
		return dp[n] = 0;
	}

	// lookup
	if(dp[n] != -1) {
		return dp[n];
	}

	// recursive case

	int a = INT_MAX;
	if(n%2 == 0) {
		// ask your friend to find minSteps reqd. to reduce n/2 to 1
		a = minStepsToOneTopDown(n/2, dp);
	}

	int b = INT_MAX;
	if(n%3 == 0) {
		// ask your friend to find minSteps reqd. to reduce n/3 to 1
		b = minStepsToOneTopDown(n/3, dp);
	}

	int c = minStepsToOneTopDown(n-1, dp);

	return dp[n] = 1 + min(a, min(b, c));

}

int minStepsToOneBottomUp(int n) {
	vector<int> dp(n+1); // 0th idx is reserved

	// base case
	dp[1] = 0;

	// recursive case
	for(int i=2; i<=n; i++) {
		int a = INT_MAX;
		if(i%2 == 0) {
			a = dp[i/2];
		}
		int b = INT_MAX;
		if(i%3 == 0) {
			b = dp[i/3];
		}
		int c = dp[i-1];
		dp[i] = 1 + min(a, min(b, c));
	}

	return dp[n];
}

int main() {

	int n = 30;

	cout << minStepsToOne(n) << endl;

	vector<int> dp(n+1, -1); // 0th idx is reserved
	cout << minStepsToOneTopDown(n, dp) << endl;
	cout << minStepsToOneBottomUp(n) << endl;
	
	return 0;
}