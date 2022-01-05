/*

Given an integer array 'nums', return the length of the longest increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without 
changing the order of the remaining elements. 

Example 1:
	Input: nums[] = [10, 9, 2, 5, 3, 7, 18]
	Output: 4
	Explanation: The longest increasing subsequence is [2, 5, 7, 18], therefore the output is 4.

Example 2:
	Input: nums[] = [0,1,0,3,2,3]
	Output: 4
	Explanation: The longest increasing subsequence is [0, 1, 2, 3], therefore the output is 4.
*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int lis_k(vector<int>& nums, int n, int i) {
	// base case
	if(i == n-1) {
		return 1;
	}

	// recursive case
	int ans = INT_MIN;
	for(int j=i+1; j<n; j++) {
		if(nums[j] > nums[i]) {
			ans = max(ans, lis_k(nums, n, j));
		}
	}

	return ans == INT_MIN ? 1 : 1 + ans;

} 

int lis(vector<int>& nums, int n) {

	int res = INT_MIN;
	for(int k=0; k<n; k++) {
		res = max(res, lis_k(nums, n, k));
	}
	return res;

}

int lis_bottom_up(vector<int>& nums, int n) {

	vector<int> dp(n);

	// base case
	dp[n-1] = 1;

	// recursive case
	for(int i=n-2; i>=0; i--) {
		int ans = INT_MIN;
		for(int j=i+1; j<n; j++) {
			if(nums[j] > nums[i]) {
				ans = max(ans, dp[j]);
			}
		}
		dp[i] = ans == INT_MIN ? 1 : 1 + ans;
	}

	int res = INT_MIN;
	for(int i=0; i<n; i++) {
		res = max(res, dp[i]);
	}

	return res;

}

int main() {

	vector<int> nums = {10, 9, 2, 5, 3, 7, 18};
	int n = nums.size();

	cout << lis(nums, n) << endl;
	cout << lis_bottom_up(nums, n) << endl;

	return 0;
}