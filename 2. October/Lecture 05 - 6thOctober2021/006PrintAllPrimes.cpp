#include<iostream>

using namespace std;

int main() {

	int N;

	cin >> N;

	// iterate over all the numbers n in the range 2 to N
	for(int n=2; n<=N; n++) {

		// check if n is a prime number or not
		int i;
		for(i=2; i<n; i++) {
			if(n%i == 0) {
				break;
			}
		}

		if(i == n) {
			cout << n << endl;
		}
	
	}

	return 0;
}