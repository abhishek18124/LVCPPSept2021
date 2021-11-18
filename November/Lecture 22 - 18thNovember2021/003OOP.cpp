#include<iostream>
#include<cstring>

using namespace std;

class customer {
public :
	int age;
	char gender;
	char name[100];
	float credits;

	void printCustomerInfo() {
		cout << "\nCustomer Information\n" << endl;
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl;
	}

	// here, I have overridden the implementation for the default constructor
	// your own implementation of the default constructor is required in case
	// you need it and you've already created a parameterised constructor
	customer() {
		cout << "\nI am inside the default constructor\n";
	}

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(char* n, int a, char g, float c) {
		cout << "\nI am inside the parameterised constructor\n";
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
	}

};

int main() {

	customer c1; // the default constructor of the customer class
			     // is invoked automatically to allocate storage
			     // to the customer object c1

	c1.age = 20;
	c1.gender = 'F';
	c1.credits = 0;
	strcpy(c1.name, "Shrutika");

	c1.printCustomerInfo();

	customer c2("Aryan", 22, 'M', 10); // the parameterised constructor of the customer class
							           // will be invoked automatically to assign values
									   // to the data members of the customer object c2

	c2.printCustomerInfo();

	return 0;
}