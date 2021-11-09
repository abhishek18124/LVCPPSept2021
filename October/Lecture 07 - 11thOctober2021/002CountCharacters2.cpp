#include<iostream>

using namespace std;

int main() {

	char ch;

	int lowercase = 0;
	int uppercase = 0;
	int digits = 0;
	int whitespaces = 0;
	int special = 0;

	while(true) {
		ch = cin.get();
		if(ch == '$') {
			// special++;
			break;
		}

		if(ch >= 'a' && ch <= 'z') {
			lowercase++;
		} else if(ch >= 'A' && ch <= 'Z') {
			uppercase++;
		} else if(ch >= '0' && ch <= '9') {
			digits++;
		} else if(ch == ' ' || ch == '\n' || ch == '\t') {
			whitespaces++;
		} else {
			special++;
		}
	}

	cout << "#lowercase = " << lowercase << endl;
	cout << "#uppercase = " << uppercase << endl;
	cout << "#digits = " << digits << endl;
	cout << "#whitespaces = " << whitespaces << endl;
	cout << "#special = " << special << endl;


	return 0;
}