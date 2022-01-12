#include<iostream>

using namespace std;

int f(int a, int b) {
	// base case
	if(b == 0) {
		// you are adding 'a' 0 times
		return 0;
	}

	// recursive case
	return a + f(a, b-1);
}

int main() {

	int a = 2;
	int b = 3;

	cout << f(a, b) << endl;

	return 0;
}