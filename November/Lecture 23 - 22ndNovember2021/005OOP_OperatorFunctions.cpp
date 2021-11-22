#include<iostream>
#include<cstring>

using namespace std;

class customer {
public :
	int age;
	string name; // member object
	
	void printCustomerInfo() {
		cout << "\nCustomer Information\n" << endl;
		cout << "Name : " << this->name << endl;
		cout << "Age : " << this->age << endl;
	}

	// here, I have overridden the implementation for the default constructor
	customer() {
		cout << "\nI am inside the default constructor of customer\n";
	}

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(string name, int age) {
		cout << "\nI am inside the parameterised constructor of customer\n";
		this->name = name;
		this->age = age;
	}

	bool isSameObject(customer* cptr) {
		return this == cptr;
	}

	// bool operator==(customer c) {
	// 	return this->name == c.name && this->age == c.age;
	// }

};

bool operator==(customer c1, customer c2) {
		return c1.name == c2.name && c1.age == c2.age;
}

int main() {

	customer c1("Hemangi", 20);
	customer c2("Hemangi", 20);

	if(c1 == c2) { // or c1.operator==(c2)
		cout << "Same Person" << endl;
	} else {
		cout << "Different Person" << endl;
	}

	return 0;
}