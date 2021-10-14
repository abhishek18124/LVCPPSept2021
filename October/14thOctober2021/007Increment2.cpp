#include<iostream>

using namespace std;

void f(int& a, int b) {
	a++;
	b++;
}

int main() {	

	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;
	f(a, b); // here a is passed by reference, b is passed by value
	cout << a << " " << b << endl;

	return 0;
}