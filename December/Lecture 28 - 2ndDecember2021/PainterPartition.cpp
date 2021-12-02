/*

https://hack.codingblocks.com/app/contests/2631/1057/problem

When we calculate the mid point 'm', we ask the question 

	can 'k' painters paint 'n' boards of given 'len' in 'm' amt. of time ?
	
	now, we can rephrase this question in two ways 

	1. how many painters are required to paint 'n' boards of given 'len' in 'm' amt. of time ?
	
	   say, 'x' painters can paint 'n' boards of given 'len' in 'm' amt. of time then
	   
	   case (a)

	   now, if x <= k then that means 'k' painters can also paint 'n' boards of given 'len' 
	   in 'm' amt. of time so we get 'true' and move towards the left to minimize time
	
	   case (b)

	   if x > k then that means 'k' painters cannot paint 'n' boards of given 'len' in 'm'
	   amt. of time i.e we get false and move towards the right.

    2. how many boards of given 'len' can 'k' painters paint in 'm' amt. of time ? 

*/

#include<iostream>
#include<climits>

using namespace std;

int numOfPaintersRequired(int n, int* len, int timeLimit) {
	int numPainters = 1;
	int time = 0;
	for(int i=0; i<n; i++) {
		// paint the ith board
		time += len[i];
		if(time > timeLimit) {
			// increase the number of painters
			numPainters++;
			// restart the painting of the ith board
			time = len[i];
		}
	}
	return numPainters;
}

int getMinTime(int k, int n, int*len) {
	int s = INT_MIN; // assign a painter to each board 
	int e = 0; // assign a single painter to paint all the N boards
	for(int i=0; i<n; i++) {
		s = max(s, len[i]);
		e += len[i];
	}
	int ans = e;

	while(s <= e) {
		int m = s + (e-s)/2;
		int x = numOfPaintersRequired(n, len, m);
		if(x <= k) {
			// 'k' painters can also do the job in <= m amt. of time
			// therefore reduce the search space from [s, e] to [s, m-1]
			ans = m;
			e = m-1;	
		} else {
			// 'k' painters cannot do the job in <= m amt. of time
			// therefore reduce the search space from [s, e] to
			// [m+1, e]
			s = m+1;
		}
	}

	return ans;
}

int main() {

	int k;
	cin >> k;

	int n;
	cin >> n;

	int* len = new int[n];
	for(int i=0; i<n; i++) {
		cin >> len[i];
	}

	cout << getMinTime(k, n, len) << endl;

	return 0;
}