#include<iostream>
#include<cstring>

using namespace std;

int stringCompare(char* str1, char* str2) {
	int i = 0; // used to iterate over str1
	int j = 0; // used to iterate over str2

	int m = strlen(str1);
	int n = strlen(str2);

	while(i<m && j<n) {
		if(str1[i] < str2[j]) {
			// str1 < str2
			return -1;
		} else if(str1[i] > str2[j]) {
			// str1 > str2
			return 1;
		} else {
			i++;
			j++;
		}
	}

	if(i < m) {
		// len(str1) > len(str2) therefore str1 > str2
		return 1;
	} else if(j < n) {
		// len(str1) < len(str2) therefore str1 < str2
		return -1;
	} 

	// len(str1) = len(str2) and all characters in str1 match with str2
	return 0;
}

int main() {

	char str1[] = "abcde";
	char str2[] = "abCde";

	// cout << (str1 == str2) << endl; // relational ops. don't work on character arrays

	// cout << strcmp(str1, str2) << endl; // 0 means str1 = str2
	//   								    // 1 means str1 > str2
	// 									// -1 means str1 < str2


	cout << stringCompare(str1, str2) << endl;


	return 0;
}