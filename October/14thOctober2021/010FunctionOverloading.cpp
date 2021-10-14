#include<iostream>
#include<cmath>

using namespace std;

double compuateAreaOfTriangle(int base, int height) {
	return 0.5 * base * height;
}

double computeSemiperimeter(int a, int b, int c) {
	return (a+b+c)/2.0;
}

double compuateAreaOfTriangle(int a, int b, int c) {
	double s = computeSemiperimeter(a, b, c);
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {

	cout << compuateAreaOfTriangle(3, 4) << endl;
	cout << compuateAreaOfTriangle(3, 4, 5) << endl;

	return 0;
}