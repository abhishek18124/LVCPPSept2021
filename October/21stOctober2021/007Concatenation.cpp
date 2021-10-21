#include<iostream>
#include<cstring>

using namespace std;

void stringConcat(char* dst, char* src) {
	int m = strlen(dst);
	int n = strlen(src);

	int i = m;
	int j = 0;

	while(j <= n) {
		dst[i] = src[j];
		i++;
		j++;
	}
}

int main() {

	char str1[21] = "hello"; // assume 0 < len(str1) <= 10 
	char str2[] = "world";  // assume 0 < len(str2) <= 10 

	cout << "Before append str1 = " << str1 << endl;

	// strcat(str1, str2);

	stringConcat(str1, str2);

	cout << "After append str1 = " << str1 << endl;
	

}