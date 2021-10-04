/*

WAP to print the following pattern

...*
..**
.***
****

Here n=4, which represents the number of rows.

*/

#include<iostream>

using namespace std;

int main() {

	int n = 10;

	int i=1;

	while(i <= n) {

		// in the ith row, print (n-i) spaces
		int j=1;
		while(j <= n-i) {
			cout << " ";
			j++;
		}

		// followed by i stars
		j = 1;
		while(j <= i) {
			cout << "*";
			j++;
		}

		cout << endl;
		i++;
	}

	return 0;
}









