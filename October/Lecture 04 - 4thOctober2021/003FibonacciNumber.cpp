#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative number = ";
	cin >> n;

	int x = 0; // initially, x represent the 0th fibonacci number
	int y = 1; // initially, y represents the 1st fibonacci number

	if(n == 0) {
		cout << "The " << n << "th" << " fibonacci number = " << x << endl;
		return 0;
	}

	int i=2;

	while(i <= n) {
		int z = x+y;
		x = y;
		y = z;
		i = i+1;
	}

	cout << "The " << n << "th" << " fibonacci number = " << y << endl;

	return 0;
}