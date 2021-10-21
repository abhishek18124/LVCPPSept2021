#include<iostream>
#include<cstring>

using namespace std;

bool checkAnagrams(char* str1, char* str2) {
	int freq1[26] = {};
	int m = strlen(str1);
	for(int i=0; i<m; i++) {
		char ch = str1[i];
		int idx = ch - 'a';
		freq1[idx]++;
	}

	for(char ch='a'; ch<='z'; ch++) {
		cout << ch << " ";
	}

	cout << endl;

	for(int i=0; i<26; i++) {
		cout << freq1[i] << " ";
	}

	cout << endl;

	int freq2[26] = {};
	int n = strlen(str2);
	for(int i=0; i<n; i++) {
		freq2[str2[i]-'a']++;
	}

	for(int i=0; i<26; i++) {
		cout << freq2[i] << " ";
	}

	cout << endl;

	for(int i=0; i<26; i++) {
		if(freq1[i] != freq2[i]) {
			return false;
		}
	}

	return true;
}

int main() {

	char str1[] = "abccbaedzed";
	char str2[] = "bccafeadedz";

	checkAnagrams(str1, str2) ? cout << "Anagrams!" << endl : cout << "Not Anagrams!" << endl;

	return 0;

}