/*

Given a string (sequence of characters) of length n, generate all of its permutations. 

Example
	
	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>
#include<set>

using namespace std;

void generatePermutaions(char* inp, int i, set<string>& s) {
	// base case
	if(inp[i] == '\0') { // i == n
		s.insert(string(inp)); // string is inserted in lexicographically sorted order
		// cout << inp << endl;
		return;
	}

	// recursive case

	// you're at the ith position, and you've decide which character
	// should be assigned to the ith position

	for(int j=i; j<strlen(inp); j++) {
		swap(inp[i], inp[j]);
		generatePermutaions(inp, i+1, s);
		swap(inp[i], inp[j]); // backtracking
	}
}

int main() {

	char inp[] = "cba";
	set<string> s;

	generatePermutaions(inp, 0, s);

	for(string str : s) {
		cout << str << endl;
	}

	return 0;
}
