/*

Write a program to check if the ith bit of a given number x is set (1).

Example :

Input : x = 6, i = 1
Output: true

Input : x = 7, i = 3
Output: false

*/

#include<iostream>
#include<bitset>

using namespace std;

int main() {

	int x = 42;
	cout << bitset<8>(42) << " : " << x << endl;

	int i = 2;

	// cout << bitset<8>(x>>i) << " : " << (x>>i) << endl;
	// cout << bitset<8>(1) << " : " << 1 << endl;
	// cout << bitset<8>((x>>i)&1) << " : " << ((x>>i)&1) << endl;

	// if((x>>i)&1) {
	// 	cout << "true" << endl;
	// } else {
	// 	cout << "false" << endl;
	// }

	(x>>i)&1 ? cout << "true" << endl : cout << "false" << endl;
	(1<<i)&x ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}









