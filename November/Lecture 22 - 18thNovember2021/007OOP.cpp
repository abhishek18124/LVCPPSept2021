#include<iostream>
#include<cstring>

using namespace std;

class customer {
public :
	int age;
	char gender;
	char* name;
	float credits;

	void printCustomerInfo() {
		cout << "\nCustomer Information\n" << endl;
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl;
	}


	customer() {
		cout << "\nI am inside the default constructor\n";
	}

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(char* n, int a, char g, float c) {
		cout << "\nI am inside the parameterised constructor\n";
		name = new char[strlen(n)+1];
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
	}

	// by default copy constructor performs shallow copy i.e. does not
	// copy dynamic memory, here we have performed deep copy
	customer(customer& c) {
		cout << "\nI am inside the copy constructor\n";
		name = new char[strlen(c.name)+1];
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}

	void operator=(customer& c) {
		cout << "\nI am inside the copy assignment operator\n";
		name = new char[strlen(c.name)+1];
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}

	// destructor of an object is invoked automatically as soon as 
	// lifecycle of an object completes i.e. it goes out of scope
	~customer() {
		cout << "\nInside the destructor of " << name << endl;
		delete [] name;
	}
};

int main() {

	// When object are constructed within the same scope
	// then the order in which they are destructed is the
	// reverse order in which are constructed.

	customer c1("Aryan", 22, 'M', 10); // the parameterised constructor of the customer class
							           // will be invoked automatically to assign values
									   // to the data members of the customer object c2


	customer c2("Avanish", 20, 'M', 100); // the parameterised constructor of the customer class
							              // will be invoked automatically to assign values
									      // to the data members of the customer object c2

	return 0;
}