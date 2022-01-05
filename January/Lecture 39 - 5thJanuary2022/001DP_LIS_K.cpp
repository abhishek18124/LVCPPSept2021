/*

Given an integer array 'nums', and an integer 'k', return the length of the longest increasing 
subsequence starting at the kth index.

A subsequence is a sequence that can be derived from an array by deleting some or no elements
without changing the order of the remaining elements. 

Example 1:
	Input: nums[] = [10, 9, 2, 5, 1, 7], k = 2
	Output: 3
	Explanation: The longest increasing subsequence starting at 2nd index is [2, 5, 7], 
	             therefore the output is 3.

Example 2:
	Input: nums[] = [0, 1, 0, 3, 2, 3], k = 1
	Output: 3
	Explanation: The longest increasing subsequence starting at the 0th index is [1, 2, 3], 
	             therefore the output is 3.
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

int lis_k_bottom_up(vector<int>& nums, int n, int k) {

	vector<int> dp(n);

	// base case
	dp[n-1] = 1;

	// recursive case
	for(int i=n-2; i>=k; i--) {
		int ans = INT_MIN;
		for(int j=i+1; j<n; j++) {
			if(nums[j] > nums[i]) {
				ans = max(ans, dp[j]);
			}
		}
		dp[i] = ans == INT_MIN ? 1 : 1 + ans;
	}

	for(int i=k; i<n; i++) {
		cout << dp[i] << " ";
	}

	cout << endl;

	return dp[k];

}

int main() {

	vector<int> nums = {10, 9, 2, 5, 1, 7};
	int n = nums.size();
	int k = 0;

	cout << lis_k(nums, n, k) << endl;
	cout << lis_k_bottom_up(nums, n, k) << endl;

	return 0;
}