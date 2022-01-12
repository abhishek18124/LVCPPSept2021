/*

Design a recursive algorithm to print string representation of a positive integer.

Example :
	Input : n = 123
	Output: one two three

*/

#include<iostream>

using namespace std;

string map[] = {"zero", "one", "two", "three", "four", "five",
		        "six", "seven", "eight", "nine"};
 
void f(int n) {
	// base case
	if(n == 0) {
		// you've extracted all the digits i.e. you've print the 
		// required spelling for n so you don't have to do anything.
		return;
	}

	// recurisve case
	
	// ask your friend to print the spelling for n/10
	f(n/10);

	// just the print the spelling for the digit at the 1s place
	int d = n%10;
	cout << map[d] << " ";

}


int main() {

	int n = 12345;

	f(n);

	cout << endl;

	return 0;
}