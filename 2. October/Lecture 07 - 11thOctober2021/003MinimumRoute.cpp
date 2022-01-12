#include<iostream>
#include<cmath>

using namespace std;

int main() {

	char ch;

	int x = 0; // used to store the net movement the person makes along the x-axis
	int y = 0; // used to store the net movement the person makes along the y axis

	while(true) {
		ch = cin.get();
		if(ch == '\n') {
			break;
		}

		if(ch == 'N') {
			y++;
		} else if(ch == 'S') {
			y--;
		} else if(ch == 'E') {
			x++;
		} else {
			x--;
		}
	}

	if(x >= 0 && y >= 0) {
		// destination is in the 1st quadrant

		// print x times 'E'
		for(int i=1; i<=x; i++) {
			cout << 'E';
		}

		// print y times 'N'
		for(int i=1; i<=y; i++) {
			cout << 'N';
		}

	} else if(x <= 0 && y >= 0) {
		// destination is in the 2nd quadrant

		// print y times 'N'
		for(int i=1; i<=y; i++) {
			cout << 'N';
		}

		// print |x| times 'W'
		for(int i=1; i<=abs(x); i++) {
			cout << 'W';
		}

	} else if(x <= 0 && y <= 0) {
		// destination is in the 3rd quadrant

		// print |y| times 'S'
		for(int i=1; i<=abs(y); i++) {
			cout << 'S';
		}

		// print |x| times 'W'
		for(int i=1; i<=abs(x); i++) {
			cout << 'W';
		}

	} else {
		// destination is in the 4th quadrant

		// print x times 'E'
		for(int i=1; i<=x; i++) {
			cout << 'E';
		}

		// print |y| times 'S'
		for(int i=1; i<=abs(y); i++) {
			cout << 'S';
		}
	}

	return 0;
}