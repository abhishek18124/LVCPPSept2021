/*

Tower of Hanoi
*/

#include<iostream>

using namespace std;

void f(int n, char src, char dst, char hlp) {
	// base case
	
	// if(n == 0) {
	// 	// do nothing
	// 	return;
	// }

	if(n == 1) {
		cout << "Move a disk from " << src << " to " << dst << endl;
		return;
	}


	// recursive case

	// move (n-1) disks from src to hlp using dst
	f(n-1, src, hlp, dst);
	// move the largest disk from src to dst
	cout << "Move a disk from " << src << " to " << dst << endl;
	// move (n-1) disks from hlp to dst using src
	f(n-1, hlp, dst, src);

}

int main() {

	int n = 3;

	f(n, 'S', 'D', 'H');

	return 0;
}
