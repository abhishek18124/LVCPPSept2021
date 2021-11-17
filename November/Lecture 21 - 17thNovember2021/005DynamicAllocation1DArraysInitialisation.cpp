#include<iostream>

using namespace std;

int main() {

	int* ptr = new int[5]{10, 20, 30, 40, 50};

	for(int i=0; i<5; i++) {
		cout << ptr[i] << " ";
	}

	cout << endl;

	delete [] ptr;

	return 0;
}