#include<iostream>

using namespace std;

int main() {

	int A[][4] = {{10, 20, 30},
				   {50, 60},
				   {90, 100, 110, 120}};

	for(int i=0; i<3; i++) {
		for(int j=0; j<4; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}