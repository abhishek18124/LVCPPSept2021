#include<iostream>

using namespace std;

int main() {

	string str = "10";

	switch(str) {
		case "10" : cout << "10" << endl; break;
		case "20" : cout << "20" << endl; break;
		default : cout << "no cases matched" << endl; break;
	}
}