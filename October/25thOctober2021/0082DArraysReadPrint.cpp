#include<iostream>

using namespace std;

int main() {	

	int A[3][4]; // declares a 2D array

	// // read row-wise
	
	// // iterate over the rows
	// for(int i=0; i<3; i++) {
	// 	// iterate over the columns
	// 	for(int j=0; j<4; j++) {
	// 		cin >> A[i][j];
	// 	}
	// }

	// // iterate over the rows
	// for(int i=0; i<3; i++) {
	// 	// iterate over the columns
	// 	for(int j=0; j<4; j++) {
	// 		cout << A[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// read-column-wise

	// iterate over the columns
	for(int j=0; j<4; j++) {
		// iterate over the rows
		for(int i=0; i<3; i++) {
			cin >> A[i][j];
		}
	}

	// print row-wise
	for(int i=0; i<3; i++) {
		// iterate over the columns
		for(int j=0; j<4; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}





	return 0;
}