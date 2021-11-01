/*

Design a recursive algorithm to convert a string into an integer.

Example :
	Input : str[] = "123"
	Output: 123

*/

#include<iostream>
#include<cstring>

using namespace std;

int f(char* str, int i) {
	// base case
	if(i == 0) {
		// digit corr. to the 0th char
		return str[i]-'0';
	}

	// recursive case
	return f(str, i-1)*10 + (str[i]-'0');
}


int main() {

	char str[] = "456";
	
	int n = strlen(str);

	int x = f(str, n-1);

	cout << x << endl;

	return 0;
}