/*

WAP to print the following pattern.

1
2 3
4 5 6
7 8 9 10

Here n=4, which represents the number of rows.

*/

#include<iostream>

using namespace std;

int main() {

	int n = 4;

	int i = 1;
	int no=1;
	while(i <= n) {
		// in the ith row, print i stars
		int j=1;
		while(j <= i) {
			cout << no << " ";
			j++;
			no++;
		}
		cout << endl;
		i++;
	}

	return 0;
}