/*

Given a phone keypad as shown below, and an n digit number, print all words which are possible by 
pressing the n digits on the keypad.

 1()     2(abc) 3(def) 
 4(ghi)  5(jkl) 6(mno)
 7(pqrs) 8(tuv) 9(wxyz)

*/

#include<iostream>

using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void pressKeypad(char* inp, int i, char* out, int j) {
    // base case
    if(inp[i] == '\0') { // i == n
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // recursive case

    // you're at the ith digit of the input sequence and you've to decide 
    // which character the ith digit should be mapped to.

    // 1. extract the ith digit
    int digit = inp[i] - '0';

    if(digit == 0 || digit == 1) {
        // skip the digit and ask your friend to take decision for the 
        // remaining digits starting with (i+1)th digit such that the
        // next free index in the out sequence is still j
        pressKeypad(inp, i+1, out, j);
        return;
    }

    // 2. extract the possible options for the ith digit
    string options = keypad[digit];

    // 3. map the ith digit to one of the characters it can be mapped to
    // for(int k=0; k<options.length(); k++) {
    //     char c_k = options[k];
    //     out[j] = c_k;
    //     pressKeypad(inp, i+1, out, j+1);
    // }

    for(char c_k : options) {
        out[j] = c_k;
        pressKeypad(inp, i+1, out, j+1);
    }

}

int main() {
	
    char inp[] = "213";
    char out[10];

    pressKeypad(inp, 0, out, 0);

	return 0;
}
