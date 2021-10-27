#include<iostream>

using namespace std;

int f(int n) {
	// base case
	if(n == 0) {
		return 1;
	}

	// recursive case
	return n * f(n-1);

}

int main() {

	int n = 4;

	cout << f(n) << endl;

	return 0;
}