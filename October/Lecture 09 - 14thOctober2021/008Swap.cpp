#include<iostream>

using namespace std;

void swapByReference(int& a, int& b) {
	swap(a, b);
}

void swapByValue(int a, int b) {
	swap(a, b);
}

int main() {

	int a = 10;
	int b = 20;

	cout << a << " " << b << endl; 

	swapByValue(a, b);

	cout << a << " " << b << endl;

	swapByReference(a, b);

	cout << a << " " << b << endl;

	return 0;
}