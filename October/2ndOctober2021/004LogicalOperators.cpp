#include<iostream>

using namespace std;

int main() {

	// Logical AND (use "and" or "&&")

	cout << "true && true = " << (true && true) << endl;
	cout << "true && false = " << (true && false) << endl;
	cout << "false && true = " << (false and true) << endl;
	cout << "false && false = " << (false and false) << endl;

	cout << "-10 && 100 = " << (-10 && 100) << endl;
	cout << "-10 && 0 = " << (-10 && 0) << endl; 
	cout << "100 && true = " << (100 && true) << endl;

	// Logical OR (use "or"/"||")

	cout << endl;

	cout << "true || true = " << (true || true) << endl;
	cout << "true || false = " << (true || false) << endl;
	cout << "false|| true = " << (false || true) << endl;
	cout << "false || false = " << (false || false) << endl;

	cout << "-10 || 100 = " << (-10 or 100) << endl;
	cout << "-10 || 0 = " << (-10 or 0) << endl; 
	cout << "100 || true = " << (100 or true) << endl;
	cout << "0 || 0 = " << (0 or 0) << endl;

	// Logical NOT (! or not)

	cout << "!true = " << (not true) << endl;
	cout << "!false = " << (!false) << endl;

	return 0;
}