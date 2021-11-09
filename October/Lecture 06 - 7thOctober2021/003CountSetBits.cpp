/*

Write a program to count number of set bits in the given number.

Example :

Input : x = 6
Output: 2

Input : x = 7
Output: 3

*/

#include<iostream>
#include<bitset>
#include<cmath>

using namespace std;

int main() {

	int x = 42;

	cout << bitset<32>(42) << " : " << x << endl;

	int count = 0;

	// for(int i=0; i<32; i++) {
	// 	// check if the ith bit is set or not

	// 	// if the ith bit is set, update the count

	// 	if((1<<i)&x) {
	// 		count++;
	// 	}

	// 	// if((x>>i)&1) {
	// 	// 	count++;
	// 	// }

	// 	// otherwise, move to the next bit
	// }

	for(int i=0; i<ceil(log2(x+1)); i++) {
		cout << i << " ";
		if((1<<i)&x) {
			count++;
		}
	}

	cout << endl;

	cout << "Number of set bits = " << count << endl;

	return 0;
}