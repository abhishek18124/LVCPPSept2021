#include<iostream>

using namespace std;

int main() {

	int n;

	cout << "Enter the value of n = " ;
	cin >> n;

	int i = 1;

	while(i <= n) {
		cout << i << " ";
		i = i + 1;
	}

	cout << endl;

	cout << "You're outside the loop" << endl;

	return 0;
}