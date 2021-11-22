#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	int age;
	string name; // member object
	
	customer(string name, int age) {
		this->age = age;
		this->name = name;
	}	
};

bool myComparator(customer c1, customer c2) {
	return c1.age < c2.age;
}

int main() {

	customer c1("Karan", 23);
	customer c2("Avanish", 20);
	customer c3("Shivam", 19);
	customer c4("Aditya", 21);
	customer c5("Nilabg", 22);

	vector<customer> v;

	v.push_back(c1);
	v.push_back(c2);
	v.push_back(c3);
	v.push_back(c4);
	v.push_back(c5);

	sort(v.begin(), v.end(), myComparator);

	for(auto x : v) {
		cout << x.age << " " << x.name << endl;
	}


	return 0;
}