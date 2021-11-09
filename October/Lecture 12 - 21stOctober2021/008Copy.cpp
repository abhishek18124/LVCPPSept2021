#include<iostream>
#include<cstring>

using namespace std;

void stringCopy(char* dst, char* src) {
	int i = 0;
	int j = 0; // you can always work with a single variable i since both i & j are always equal for this program
	int n = strlen(src);
	while(j <= n) {
		dst[i] = src[j];
		i++;
		j++;
	}
}

int main() {

	char str1[11] = "hello"; // 0 < len(str1) <= 10
	char str2[] = "helloworld"; // 0 < len(str2) <= 10

	cout << "Before copy str1 = " << str1 << endl;

	// strcpy(str1, str2);

	stringCopy(str1, str2);

	cout << "After copy str1  = " << str1 << endl;


	return 0;
}