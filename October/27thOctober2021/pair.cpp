#include<iostream>

using namespace std;

int main() {

	// pair<int, int> p; // declaration

	// // p.first  = 10;
	// // p.second = 20;

	// p = make_pair(10, 20);

	// cout << p.first << " " << p.second << endl;

	// pair<char, string> p2 = make_pair('a', "abhishek");
	// cout << p2.first << " " << p2.second << endl;

	pair<int, char> p3(50, 'A');
	cout << p3.first << " " << p3.second << endl;

	return 0;
}