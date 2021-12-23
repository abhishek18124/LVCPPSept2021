/*

	Implement a phonebook storing mapping between person's name and their phone numbers 
	using an unordered_map.

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phonebook;

	phonebook["Abhishek"].push_back("9999366996");
	phonebook["Abhishek"].push_back("1123455667");

	phonebook["Shrutika"].push_back("0123455667");
	phonebook["Saksham"].push_back("123445667");
	phonebook["Saksham"].push_back("1259494875");
	phonebook["Utsav"].push_back("012334566");

	cout << "size : " << phonebook.size() << endl;

	for(auto p : phonebook) {
		cout << p.first << " : ";
		for(auto x : p.second) {
			cout << x << " ";
		}
		cout << endl;
	}

	if(phonebook.find("Abhishek") != phonebook.end()) {
		vector<string> phoneNumbers = phonebook["Abhishek"];
		for(auto no :  phoneNumbers) {
			cout << no <<  " ";
		}
		cout << endl;
	}


	return 0;
}