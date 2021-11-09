#include<iostream>

using namespace std;

void greet() {
	cout << "Hello from inside the greet() function" << endl;
	return; // optional
}

int main() {

	cout << "Hello from inside the main() function, before calling greet()" << endl;
	greet();
	cout << "Hello from inside the main() function, after calling greet()" << endl;
	
	return 0;
}