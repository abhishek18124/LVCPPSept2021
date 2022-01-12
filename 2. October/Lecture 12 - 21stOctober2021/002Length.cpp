#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[] = "hello world";
	int cnt = 0;
	for(int i=0; str[i] != '\0'; i++) {
		cnt++;
	}

	cout << "Length of the string = " << cnt << endl;
	cout << "Length of the string = " << strlen(str) << endl;

	return 0;
}