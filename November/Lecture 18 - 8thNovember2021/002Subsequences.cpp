/*

Given a string (sequence of characters) of length n, generate all of its subsequences. 

A subsequence of a given string (sequence) is a string (sequence) that is generated by 
removing zero or more characters from the given string (sequence) without changing its 
order.

Example
	
	Input : inp[] = "abc"
	Output: ["", "c", "b", "bc", "a", "ac", "ab", "abc"]

Constraints
 
  1 < n < 10

*/

#include<iostream>

using namespace std;

void generateSubsequences(char* inp, int i, char* out, int j) {
	// base case 
	if(inp[i] == '\0') { // i == n
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// you're at the ith character trying to decide whether to include it
	// in the output sequence or exclude it from the output sequence

	// 1. include the ith character in the output sequence
	out[j] = inp[i];
	generateSubsequences(inp, i+1, out, j+1);
	
	// 2. exclude the ith character from the output sequence
	generateSubsequences(inp, i+1, out, j);
}

int main() {

	char inp[] = "abcd";
	char out[10];

	generateSubsequences(inp, 0, out, 0);

	return 0;
}