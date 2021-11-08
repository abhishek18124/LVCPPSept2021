/*

Given string str of size n, design a recursive algorithm to replace all occurrences of pi 
with 3.14 in the given string and print the modified string.

Example : 
	Input : inp[] = "pippppiiiipi"
	Output: out[] = "3.14ppp3.14iii3.14"

	Input : inp[] = "pip"
	Output: out[] = "3.14p"

	Input : inp[] = "xpix"
	Output: out[] = "x3.14x"

Constraints :

	1 < n < 10 

*/

#include<iostream>

using namespace std;

void replacePi(char* inp, int i) {
	// base case
	if(inp[i] == '\0') { // i == n
		// you've an empty str so you don't have to do anything
		return;
	}


	// recursive case
	if(inp[i] == 'p' and inp[i+1] == 'i') {
		// shift all the characters starting from the (i+2)th idx 2-steps to the right
		
		int j = i+2;
		while(inp[j] != '\0') {
			j++;
		}

		while(j >= i+2) {
			inp[j+2] = inp[j];
			j--;
		}

		// replace "pi" at the (i, i+1)th idx with "3.14"
		inp[i] = '3';
		inp[i+1] = '.';
		inp[i+2] = '1';
		inp[i+3] = '4';
		// ask your friend to replace "pi" with 3.14 in the substring starting from the (i+4)th index
		replacePi(inp, i+4);

	} else {
		// ask your friend to replace "pi" with "3.14" in the substring starting from the (i+1)th idx
		replacePi(inp, i+1);
	}
}

int main() {

	char inp[20] = "pippppiiiipi";

	replacePi(inp, 0);

	cout << inp << endl;

	return 0;
}
