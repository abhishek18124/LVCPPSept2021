#include<iostream>

using namespace std;

int add(int a, int b, int c=0, int d=0) {
	return a+b+c+d;
}

int add(float a, int b, float c=0, float d=0) {
	return a+b+c+d;
}

int main() {

	cout << add(1, 2, 3, 4) << endl;
	cout << add(1, 2, 3) << endl;
	cout << add(1, 2) << endl;

	return 0;
}