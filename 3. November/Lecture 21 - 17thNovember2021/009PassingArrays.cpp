#include<iostream>

using namespace std;

void f(int** A) {

}

int main() {

	int A[3][4];

	f(A); // leads to error, static and dynamically created 2D arrays cannot be
		  // used interchangbly unlike 1D arrays.

	return 0;
}