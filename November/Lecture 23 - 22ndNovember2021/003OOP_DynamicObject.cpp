#include<iostream>
#include<cstring>

using namespace std;

class customer {
public :
	int age;
	string name; // member object
	
	void printCustomerInfo() {
		cout << "\nCustomer Information\n" << endl;
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
	}

	// here, I have overridden the implementation for the default constructor
	customer() {
		cout << "\nI am inside the default constructor of customer\n";
	}

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(string n, int a) : name(n), age(a) {
		cout << "\nI am inside the parameterised constructor of customer\n";
	}

};

int main() {

	customer* cptr1 = new customer; // it will default construct a customer object
	 					            // on the heap segment of the memory.



	customer* cptr2 = new customer("Saksham", 20); // it will invoke the parameterised constructor
												   // while dynamically creating the customer object


	cptr2->printCustomerInfo();

	return 0;
}