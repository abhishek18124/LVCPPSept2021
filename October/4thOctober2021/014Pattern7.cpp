/*

WAP to print the following pattern

. . . 1
. . 2 3 2
. 3 4 5 4 3
4 5 6 7 6 5 4

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

		// followed by i numbers in the increasing order
		// starting with i
		j = 1;
		int no = i;
		while(j <= i) {
			cout << no;
			j++;
			no++;
		}

		// followed by (i-1) numbers in the decreasing order
		// starting with 2i-2
		no = no-2;// no = 2*i-2;
		j = 1;
		while(j <= i-1) {
			cout << no;
			j++;
			no--;
		}

		cout << endl;
		i++;
	}

	return 0;
}









