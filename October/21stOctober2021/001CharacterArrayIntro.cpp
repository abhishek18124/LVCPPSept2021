#include<iostream>

using namespace std;

int main() {

	char A[] = {'x', 'y', 'z', '\0'};
	cout << A << endl;

	char B[100] = {'a', 'b', 'c', '\0'};
	cout << B << endl;

	char C[] = "hello"; // \0 is added by default by C++
	cout << C << endl;

	char D[6] = "world";
	cout << D << endl;

	char E[20] = "hello world";
	for(int i=0; E[i] != '\0'; i++) {
		cout << E[i] << " ";
	}
	cout << endl;

	return 0;
}