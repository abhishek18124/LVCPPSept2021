/*

WAP to print the following pattern

. . . 1
. . 2 3
. 3 4 5
4 5 6 7

Here n=4, which represents the number of rows.

*/

#include<iostream>

using namespace std;

int main() {

	int n = 4;

	int i=1;

	while(i <= n) {

		// in the ith row, print (n-i) spaces
		int j=1;
		while(j <= n-i) {
			cout << " ";
			j++;
		}

		// followed by i numbers
		j = 1;
		int no = i;
		while(j <= i) {
			cout << no;
			j++;
			no++;
		}

		cout << endl;
		i++;
	}

	return 0;
}









