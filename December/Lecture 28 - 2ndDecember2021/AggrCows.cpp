/*

https://www.spoj.com/problems/AGGRCOW/

*/

#include<iostream>
#include<climits>

using namespace std;

bool canPlaceCows(int n, int c, int* pos, int m) {
	// place the 1st cow in the 1st stall
	int numOfCowsPlaced = 1;
	// track the position of the last cow you've place
	int prevCowPosition = pos[0];
	for(int i=1; i<n; i++) {
		// can I place the next cow in the stall at the ith position ?
		if(pos[i]-prevCowPosition >= m) {
			numOfCowsPlaced++;
			prevCowPosition = pos[i];
			if(numOfCowsPlaced == c) {
				// you've managed to place c cows in n stalls
				return true;
			}
		}
	}
	return false;
}

// void updatePositions(int n, int c, int* pos, int m, vector<int>& v) {
// 	// place the 1st cow in the 1st stall
// 	int numOfCowsPlaced = 1;
// 	// track the position of the last cow you've place
// 	int prevCowPosition = pos[0];
// 	v.push_back(prevCowPosition);
// 	for(int i=1; i<n; i++) {
// 		// can I place the next cow in the stall at the ith position ?
// 		if(pos[i]-prevCowPosition >= m) {
// 			numOfCowsPlaced++;
// 			prevCowPosition = pos[i];
// 			v.push_back(prevCowPosition);
// 		}
// 	}
// }

int largestMinDist(int n, int c, int* pos) {

	int s = INT_MAX; // place the two cows at the two closest stalls
	for(int i=1; i<n; i++) {
		if(pos[i]-pos[i-1] < s) {
			s = pos[i]-pos[i-1];
		}
	}

	int e = pos[n-1]-pos[0]; // place the two cows at extreme ends
	int ans = s;

	// vector<int> v;

	while(s <= e) {
		int m = s + (e-s)/2;
		if(canPlaceCows(n, c, pos, m)) {
			// reduce the search space from [s, e] to [m+1, e]
			// updatePositions(n, c, pos, m, v);
			ans = m;
			s = m+1;
		} else {
			// reduce the search from [s, e] to [s, m-1]
			e = m-1;
		}
	}

	// for(int i=0; i<c; i++) {
	// 	cout << v[v.size()-1-i] << " ";
	// }

	return ans;

}

int main() {

	// int t;
	// cin >> t;

	// int n, c;
	// int* pos = new int[n];

	// while(t--) {
	// 	cin >> n >> c;
	// 	for(int i=0; i<n; i++) {
	// 		cin >> pos[i];
	// 	}
	// 	sort(pos, pos+n);
	// 	cout << largestMinDist(n, c, pos) << endl;
	// }	

	int n = 5;
	int c = 3;
	int pos[] = {1, 2, 4, 8, 9};
	cout << largestMinDist(n, c, pos) << endl;

	return 0;
}