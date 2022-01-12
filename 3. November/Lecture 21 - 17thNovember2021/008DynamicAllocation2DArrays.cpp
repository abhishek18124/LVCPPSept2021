#include<iostream>

using namespace std;

void print2DArray(int** ptr, int m, int n) {
	for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cout << ptr[i][j] << " "; // or *(*(ptr+i)+j)
			}
			cout << endl;
		}
	cout << endl;
}

int main() {

	int m;
	cin >> m;

	int n;
	cin >> n;

	int** ptr = new int*[m];
	for(int i=0; i<m; i++) {
		ptr[i] = new int[n];
	}

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> ptr[i][j]; // or *(*(ptr+i)+j)
		}
	}

	print2DArray(ptr, m, n);

	for(int i=0; i<m; i++) {
		delete [] ptr[i]; // deletes the ith row of the given 2D array
	}

	delete [] ptr; // deletes the 1D array of integer pointers of size m

	return 0;
}