#include<iostream>
#include<cstring>

using namespace std;

bool checkPalindrome(char* str) {
	int i = 0;
	int j = strlen(str)-1;

	while(i < j) {
		if(str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main() {

	char str[] = "acbca";

	checkPalindrome(str) ? cout << "Palindrome!" << endl : cout << "Not a Palindrome!" << endl;

}