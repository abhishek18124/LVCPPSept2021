#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void reverse(char* str) { // or char str[]
	int i = 0;
	int j = strlen(str) - 1;

	while(i<j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}
}

int main() {

	char str[] = "hello world";

	cout << "Before reverse =  " << str << endl;

	// reverse(str);

	// strrev(str);

	reverse(str, str+strlen(str));

	cout << "After reverse  =  " << str << endl;

	int A[] = {10, 20, 30, 40, 50};
	int n = sizeof(A) / sizeof(int);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	reverse(A, A+n);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}