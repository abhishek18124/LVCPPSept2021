#include<iostream>

using namespace std;

int factorial(int n) {
	int fact = 1;
	
	// // compute the factorial by iterating over 1 to n from R to L
	// for(int i=n; i>0; i--) {
	// 	fact *= i;
	// }

	// compute the factorial by iterating over 1 to n from L to R
	for(int i=1; i<=n; i++) {
		fact *= i;
	}

	return fact;
}

int ncr(int n, int r) {
	return factorial(n) / (factorial(r)*factorial(n-r));
}

int main() {

	cout << factorial(5) << endl;
	cout << ncr(5, 2) << endl;
	return 0;
}
