/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the 
input string is valid.

An input string is valid if:
	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.

Examples 
	
	Input: s = "{[()]}"
	Output: true

	Input: s = "{[]()}"
	Output: true

	Input: s = "([)]"
	Output: false
	
*/

#include<iostream>
#include<stack>

using namespace std;

// bool isValid(string str) {
//  	stack<char> s;
//  	for(char ch : str) {
//  		if(ch == '{' || ch == '(' || ch == '[') {
//  			s.push(ch);
//  		} else {
//  			// ch represents a closing bracket
//  			if(ch == '}') {
//  				if(!s.empty() && s.top() == '{') {
//  					s.pop();
//  				} else {
//  					return false;
//  				}
//  			} else if(ch == ')') {
//  				if(!s.empty() && s.top() == '(') {
//  					s.pop();
//  				} else {
//  					return false;
//  				}
//  			} else {
//  				if(!s.empty() && s.top() == '[') {
//  					s.pop();
//  				} else {
//  					return false;
//  				}
//  			}
//  		}
//  	}    

//  	return s.empty();

// }

bool isValid(string str) {
 	stack<char> s;
 	for(char ch : str) {
 		switch(ch) {
 			case '{' : 
 			case '[' :
 			case '(' : s.push(ch); break;
 			case '}' : if(!s.empty() && s.top() == '{') s.pop(); else return false; break;
 			case ']' : if(!s.empty() && s.top() == '[') s.pop(); else return false; break;
 			case ')' : if(!s.empty() && s.top() == '(') s.pop(); else return false; break;
 		}
 	}    

 	return s.empty();

}

int main() {

	string str = "{[]()}{{}}";

	isValid(str) ? cout << "balanced" << endl : 
				   cout << "unbalanced" << endl;

	return 0;
}