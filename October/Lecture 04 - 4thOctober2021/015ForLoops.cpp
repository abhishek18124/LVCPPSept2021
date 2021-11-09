#include<iostream>

using namespace std;

int main() {

	int n = 10;

	for(int i=1; i<=n; i++) {
		cout << i << " ";
	}
	
	cout << endl;

	int i = 1;
	while(i <= n) {
		cout << i << " ";
		i++;
	}

	cout << endl;

	int j;
	for(j=1; j<=n; j++) {
		cout << j << " ";
	}

	cout << endl;

	for(int i=1, j=10; i<j; i++, j--) {
		cout << i << " " << j << endl;
	}

	return 0;
}