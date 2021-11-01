/*

Given a string str, design a recursive algorithm to move all the occurrence of letter x 
to the end of the string str.

Example 
	Input : str = "axbcxdxfx"
	Output: str = "abcdfxxxx"

	Input : str = "xabcxdxfx"
	Output: str = "abcdfxxxx"

*/

#include<iostream>

using namespace std;

string f(string str) {
	// base case
	if(str.empty()) {
		// At this point, str is empty to you don't have to 
		// move anything just return str and you are done.
		return str;
	}

	// recursive case

	// ask your friend to move all 'x' characters in the substring that
	// starts at the 1st idx to the end
	string subString = str.substr(1);
	string subStringFromMyFriend = f(subString);

	// now, you've to check if the character at the 0th idx matches
	// with 'x' or not ?
	string firstChar = str.substr(0, 1);

	if(firstChar == "x") {
		// append firstChar to the end of A
		return subStringFromMyFriend + firstChar;
	} else {	
		// prepend firstChar to the beginning of A
		return firstChar + subStringFromMyFriend;
	}
}

int main() {

	string str = "xaxbxc";

	cout << f(str) << endl;

	return 0;
}
