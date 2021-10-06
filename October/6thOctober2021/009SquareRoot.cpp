#include<iostream>
#include<cmath>

using namespace std;

int main() {


	// int n;
	// cout << "Enter a non-negative integer : ";
	// cin >> n;

	int n = 24;

	cout << sqrt(n) << endl;

	double sqr = 0;
	float inc = 1;
	int p = 4;

	for(int i=0; i<=p; i++) {
		while(sqr*sqr <= n) {
			sqr = sqr + inc;
		}

		sqr = sqr - inc;
		inc = inc / 10;
	}

	// while(sqr*sqr <= n) {
	// 	sqr = sqr + 1;
	// }

	// sqr = sqr - 1;

	// while(sqr*sqr <= n) {
	// 	sqr = sqr + 0.1;
	// }

	// sqr = sqr - 0.1;

	// while(sqr*sqr <= n) {
	// 	sqr = sqr + 0.01;
	// }

	// sqr = sqr - 0.01;

	// while(sqr*sqr <= n) {
	// 	sqr = sqr + 0.001;
	// }

	// sqr = sqr - 0.001;



	cout << "Square root of " <<  n << " : " << sqr << endl;

	return 0;
}