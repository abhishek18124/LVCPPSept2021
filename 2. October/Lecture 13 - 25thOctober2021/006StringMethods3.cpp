#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string str("Hello World");

	cout << str.substr() << endl; // pos=0, len
	cout << str.substr(2) << endl;
	cout << str.substr(2, 5) << endl;

	// reverse(str.begin(), str.end());
	// reverse(str.begin(), str.begin()+5); // [start, end)
	// cout << str << endl;

	char* ch = (char*)str.c_str(); // returns the character array stored inside the str object
	cout << ch << endl;

	return 0;
}