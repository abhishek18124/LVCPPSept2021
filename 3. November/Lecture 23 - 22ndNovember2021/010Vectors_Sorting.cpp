#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool myComparatorLesser(int a, int b) {
	// if(a < b) {
	// 	// swapping is not required
	// 	return true;
	// } else {
	// 	// swapping is required 
	// 	return false;
	// }
	return a < b;
}

bool myComparatorGreater(int a, int b) {
	return a > b;
}


int main() {

	vector<int> v = {1, 0, 2, 4, 3};

	reverse(v.begin(), v.end());

	for(auto x : v) {
		cout << x << " ";
	}

	cout << endl;

	// Sorting a sequence container

	// sort(v.begin(), v.end()); // sorts the container in the increasing order
	// sort(v.begin(), v.end(), less<int>()); // sorts the container in the increasing order
	sort(v.begin(), v.end(), myComparatorLesser);

	for(auto x : v) {
		cout << x << " ";
	}

	cout << endl;

	// sort(v.rbegin(), v.rend()); // sorts the container in the decreasing order
	// sort(v.begin(), v.end(), greater<int>());
	sort(v.begin(), v.end(), myComparatorGreater);

	for(auto x : v) {
		cout << x << " ";
	}

	cout << endl;

	int A[] = {5, 4, 3, 2, 1};
	int n = sizeof(A) / sizeof(int);

	sort(A, A+n);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}