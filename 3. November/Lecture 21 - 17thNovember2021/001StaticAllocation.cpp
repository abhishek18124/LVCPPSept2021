#include<iostream>

using namespace std;

int* f(int x, int y) {
	int z = x + y;
	return &z;
}

int main() {

	int x = 10;
	int y = 20;

	int* zptr = f(x, y);
	// cout << *zptr << endl; // illegal access to a memory
				           // which has been already deallocated

	return 0;
}