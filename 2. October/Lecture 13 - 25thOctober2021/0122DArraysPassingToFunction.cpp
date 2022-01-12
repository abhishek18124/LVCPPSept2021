#include<iostream>

using namespace std;

// int computeSum(int A[][2]) {
// 	int sum = 0;
// 	for(int i=0; i<2; i++) {
// 		for(int j=0; j<2; j++) {
// 			sum += A[i][j];
// 		}
// 	}
// 	return sum;
// }


int computeSum(int (*A)[2]) {
	int sum = 0;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			sum += A[i][j];
		}
	}
	return sum;
}

int main() {

	int A[][2]  = {{1, 2},
  					{3, 4}};

  	cout << computeSum(A) << endl;

	return 0;
}