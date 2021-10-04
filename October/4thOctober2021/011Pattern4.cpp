/*

WAP to print the following pattern.

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1

Here n=5, which represents the number of rows.

*/

#include<iostream>

using namespace std;

int main() {

	int n = 5;

	int i = 1;
	while(i <= n) {
		// in the ith row, print i nos.
		int j=1;
		int no;

		if(i%2 == 0) {
			// you're in an even row
			no = 0;
		} else {
			// you're in an odd row
			no = 1;
		}

		while(j <= i) {
			cout << no;
			j++;
			no = 1-no;
		}
		cout << endl;
		i++;
	}

	return 0;
}