#include<iostream>

using namespace std;

void readString(char* str, char delimiter='\n') {
	char ch;
	int i = 0;
	while(true) {
		ch = cin.get();
		if(ch == delimiter) {
			break;
		}
		str[i] = ch;
		i++;
	}
	str[i] = '\0'; // explicitly terminate with '\0'
}

int main() {

	char str[100];

	// cin >> str; // \0 is added by default here
	// readString(str);
	cin.getline(str, 5, '$');

	cout << "String entered by the user = " << str << endl;

	return 0;
}