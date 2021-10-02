#include<iostream>

using namespace std;

int main() {

	int x;

	cin >> x;

	if(x > 10) {
		cout << "Yes, " << x << " is greater than 10" << endl;
	}

	cout << "You're outside the body of if-statement" << endl;
	return 0;
}