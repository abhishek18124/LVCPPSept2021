#include<iostream>

using namespace std;

int main() {

	int A[5] = {10, 20, 10, 30, 40};
	int n = sizeof(A) / sizeof(int);
	int key = 40;
	// int result = -1;

	// for(int i=0; i<n; i++) {
	// 	if(A[i] == key) {
	// 		result = i;
	// 		break;
	// 	}
	// }

	// cout << result << endl;

	int i;
	for(i=0; i<n; i++) {
		if(A[i] == key) {
			break;
		}
	}

	if(i == n) {
		cout << -1 << endl;
	} else {
		cout << i << endl;
	}

	return 0;
}