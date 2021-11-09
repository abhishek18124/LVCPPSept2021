#include<iostream>

using namespace std;

int main() {

	int p;

	cout << "Enter principle = ";
	cin >> p;

	int r;

	cout << "Enter rate = ";
	cin >> r;

	int t;

	cout << "Enter time = ";
	cin >> t;

	float si = p*r*t / 100.0;

	cout << "Simple Interest = " << si << endl;

	return 0;
}