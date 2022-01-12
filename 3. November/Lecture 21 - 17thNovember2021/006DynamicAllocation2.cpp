#include<iostream>

using namespace std;

int* f(int x, int y) {
	int* zptr = new int;
	*zptr = x + y;
	return zptr;
}

int main() {

	int x = 10;
	int y = 20;

	int* zptr = f(x, y);
	cout << *zptr << endl;
	
	return 0;
}