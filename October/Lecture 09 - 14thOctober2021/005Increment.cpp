#include<iostream>

using namespace std;

void increment(int a) {
	a++;
}


int main() {
	int a = 10;
	cout << "a = " << a << endl;
	increment(a);
	cout << "a = " << a << endl;

	return 0;
}