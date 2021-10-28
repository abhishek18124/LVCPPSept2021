#include<iostream>

using namespace std;

void f(int n) {
	// base case
	if(n == 0) {
		return;
	}

	// recursive case
	f(n-1);
	cout << n << " ";

}

int main() {

	int n = 10;

	f(n);

	return 0;
}