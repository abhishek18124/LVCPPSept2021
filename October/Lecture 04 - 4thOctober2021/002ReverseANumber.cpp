#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;

	cout << "Enter a number : ";
	cin >> n;

	bool flag = true; // assume number to be positive

	if(n < 0) {
		n = abs(n);
		flag = false;
	}

	int reversedNumber = 0;

	while(n > 0) { 
		int digit = n%10;	
		reversedNumber = reversedNumber*10 + digit;
		n = n/10;
	}

	if(flag) {
		cout << "The reversed number = " << reversedNumber << endl;
	} else {
		cout << "The reversed number = " << -reversedNumber << endl;
	}

	return 0;
}