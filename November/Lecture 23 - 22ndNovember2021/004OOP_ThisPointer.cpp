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

};

int main() {

	customer c1("Hemangi", 20);

	c1.printCustomerInfo();

	// c1.isSameObject(&c1) ? cout << "true" << endl : cout << "false" << endl;

	// customer c2("Meha", 20);

	// c1.isSameObject(&c2) ? cout << "true" << endl : cout << "false" << endl;


	return 0;
}