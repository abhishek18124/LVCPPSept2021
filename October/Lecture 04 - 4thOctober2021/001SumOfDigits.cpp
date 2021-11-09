// Sum of digits

#include<iostream>

using namespace std;

int main() {

	int n;

	cout << "Enter a number : ";
	cin >> n;

	int sum = 0;
	while(n > 0) {
		int digit = n%10;
		sum = sum+digit;
		n = n/10; // integer division
	}

	cout << "The sum of digits = " << sum << endl;

	return 0;
}