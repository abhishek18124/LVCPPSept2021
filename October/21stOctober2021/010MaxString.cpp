#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int n;
	cin >> n;

	cin.ignore();

	char maxString[100];
	int maxLength = 0; // or INT_MIN

	char temp[100];

	int i = 0;
	while(i < n) {
		cin.getline(temp, 100); // you can use cin>> but it will not read as soon as it encounters whitespace
		if((int)strlen(temp) > maxLength) {
			maxLength = strlen(temp);
			strcpy(maxString, temp);
		}
		i++;
	}

	cout << "The maximum length string is equal to \"" << maxString 
	     << "\" and its length = " << maxLength << endl;


}