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
};

int main() {

	customer c1("Aryan", 22, 'M', 10); // the parameterised constructor of the customer class
							           // will be invoked automatically to assign values
									   // to the data members of the customer object c2

	cout << "c1.name = " << c1.name << endl;

	customer c2(c1); // invokes the copy constructor to construct c2 as a copy of c1

	cout << "c2.name = " << c2.name << endl;

	strcpy(c2.name, "Aditya");

	cout << "c2.name = " << c2.name << endl;
	cout << "c1.name = " << c1.name << endl;

	customer c3;
	c3 = c1;

	cout << "c3.name = " << c3.name << endl;

	strcpy(c3.name, "Pankhuri");
	cout << "c3.name = " << c3.name << endl;
	cout << "c1.name = " << c1.name << endl;


	return 0;
}