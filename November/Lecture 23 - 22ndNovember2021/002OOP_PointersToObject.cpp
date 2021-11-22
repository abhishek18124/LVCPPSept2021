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

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(string n, int a) : name(n), age(a) {
		cout << "\nI am inside the parameterised constructor of customer\n";
	}

};

int main() {

	customer c("Chirag", 20);

	customer* cptr = &c;

	// cout << "Name : " << (*cptr).name << "  " << cptr->name << endl;
	// cout << "Age : " << (*cptr).age << " " << cptr->age << endl;
	
	// (*cptr).printCustomerInfo();
	// cptr->printCustomerInfo();

	return 0;
}