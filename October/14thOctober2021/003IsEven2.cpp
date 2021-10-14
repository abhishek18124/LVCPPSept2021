#include<iostream>

using namespace std;

bool isEven(int n) {
	// if(n%2 == 0) {
	// 	return true;
	// } else {
	// 	return false;
	// }

	// return n%2 == 0 ? true : false;

	return n%2 == 0;
}

int main() {

	// bool result;

	// result = isEven(4);

	// if(result == true) { 
	// 	cout << "even" << endl;
	// } else {
	// 	cout << "odd" << endl;
	// }

	// if(result) { 
	// 	cout << "even" << endl;
	// } else {
	// 	cout << "odd" << endl;
	// }

	// result ? cout << "even" << endl : cout << "odd" << endl;

	isEven(3) ? cout << "even" << endl : cout << "odd" << endl;

	return 0;
}