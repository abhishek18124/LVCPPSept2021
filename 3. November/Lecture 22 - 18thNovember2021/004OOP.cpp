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

	// here, I am overriding the implementation of the default copy constructor
	// for the customer class
	customer(customer& c) {
		cout << "\nI am inside the copy constructor\n";
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}

	// if you pass customer object c by value then first copy constructor
	// will be invoked and then we will enter inside the body of the copy
	// assignment operator
	void operator=(customer& c) {
		cout << "\nI am inside the copy assignment operator\n";
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}

};

int main() {

	customer c1("Aryan", 22, 'M', 10); // the parameterised constructor of the customer class
							           // will be invoked automatically to assign values
									   // to the data members of the customer object c2

	c1.printCustomerInfo();

	// customer c2 = c1;
	customer c2(c1);   // the default copy constructor of the customer class will be invoked
					   // automatically to allocate storage for c2 and then copying the content
					   // of c1 into c2

	c2.printCustomerInfo();

	customer c3; // invokes the default constructor
	c3 = c1;     // invokes the default copy assignment operator 
				 // function for copying the content of c1 into c3
	// c3.operator=(c1); // explicitly invoking the copy assignment operator

	c3.printCustomerInfo();

	return 0;
}