/*

WAP to print the following pattern.

1
12
123
1234

Here n=4, which represents the number of rows.

*/

#include<iostream>

using namespace std;

int main() {

	int n = 4;

	int i = 1;
	while(i <= n) {
		// in the ith row, print i stars
		int j=1;
		int no=1;
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