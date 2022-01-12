#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[] = ".....ab$c.d/e/..f$.ghi/j$kl/";
	char dl[] = "./$";

	char* token = strtok(str, dl);

	// cout << token << endl;

	// token = strtok(NULL, dl);

	// cout << token << endl;

	// token = strtok(NULL, dl);

	// cout << token << endl;

	while(token != NULL) {
		cout << token << endl;
		token = strtok(NULL, dl);
	}

	cout << str << endl;

	return 0;
}