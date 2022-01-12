#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* xptr = &x;
	double* dptr = (double*)&x;

	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << endl;
	cout << "dptr = " << dptr << endl;
	cout << "sizeof(dptr) = " << sizeof(dptr) << endl;

	char ch = 'A';
	char* chptr = &ch;

	cout << "&ch = " << (double*)&ch << endl;
	cout << "chptr = " << (double*)chptr << endl;

	return 0;
}