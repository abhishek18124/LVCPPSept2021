#include<iostream>

using namespace std;

int main() {

	// int a = 0;
	// int b = 10;

	// // if(b < 0 or a++) {
	// // 	a++;
	// // } else {
	// // 	b++;
	// // }

	// // cout << a << " " << b << endl; // 1, 11

	// if(b < 0 or ++a) {
	// 	a++;
	// } else {
	// 	b++;
	// }

	// cout << a << " " << b << endl; // 2, 10

	int a = 10;
	int b = a++ + ++a;

	cout << a << " " << b << endl;

	return 0;
}