/*

Write a program to print the following pattern

A B C D E E D C B A
A B C D D C B A
A B C C B A
A B B A
A A

here, n i.e. number of rows is equal to five.

*/

#include<iostream>

using namespace std;

int main() {

	int n = 5;

	for(int i=1; i<=n; i++) {
		// in the ith row, we have to print (n-i+1) characters
		// in the increasing order that start with 'A'
		char ch = 'A';
		for(int j=1; j<=n-i+1; j++) {
			cout << ch << " " ;
			ch++;
		}

		// At this point, ch contains the character that comes after
		// the character with which the increasing pattern ends
		// therefore we have to decrement it by 1 before starting the
		// 2nd inner loop

		ch--;

		// followed by (n-i+1) characters in the decreasing order
		// that starts with the character at which the increasing
		// pattern ends

		for(int j=1; j<=n-i+1; j++) {
			cout << ch << " ";
			ch--;
		}


		cout << endl;
	}

	return 0;
}




