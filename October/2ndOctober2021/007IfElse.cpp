#include<iostream>

using namespace std;

int main() {

	int age;

	cout << "Enter your age = ";
	cin >> age;

	if(age >= 18) {
		cout << "You're eligible to vote" << endl;
	} else {
		cout << "You're not eligible to vote" << endl;
	}

	cout << "You're outside the if-else block" << endl;

	return 0;
}