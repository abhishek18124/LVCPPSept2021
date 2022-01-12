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
	customer() {
		cout << "\nI am inside the default constructor\n";
	}

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(char* n, int a, char g, float c) {
		cout << "\nI am inside the parameterised constructor 1\n";
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
	}


	// // here, I am implementing a parameterised constructor to assign values
	// // to the data members of an object when it declared
	customer(char* n, int a, char g) {
		cout << "\nI am inside the parameterised constructor 2\n";
		strcpy(name, n);
		age = a;
		gender = g;
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

	customer c3("Avanish", 20, 'M'); // the parameterised constructor of the customer class
							         // will be invoked automatically to assign values
									 // to the data members of the customer object c3

	c3.printCustomerInfo();



	return 0;
}