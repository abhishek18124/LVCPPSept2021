#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int* xptr = &x;
	cout << "xptr = " << xptr << endl;
	xptr += 2;
	cout << "xptr = " << xptr << endl;

	return 0;
}