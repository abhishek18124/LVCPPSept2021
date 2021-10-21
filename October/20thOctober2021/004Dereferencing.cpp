#include<iostream>

using namespace std;

int main() {

	int x = 520;
	int* xptr = &x;

	cout << "x = " << x << endl;
	cout << "xptr = " << xptr << endl;
	cout << "*xptr = " << *xptr << endl;

	char* chptr = (char*)&x;
	cout << "*chptr = " << (int)*chptr << endl;

	double* dptr = (double*)&x;
	cout << "*dptr =  " << *dptr << endl;

	return 0;
}