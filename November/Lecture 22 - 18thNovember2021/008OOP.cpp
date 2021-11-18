#include<iostream>

using namespace std;

class customer {

	int age;
	char gender;
	string name;
	float credits;

public :
	
	void printCustomerInfo() {
		cout << "\nCustomer Information\n" << endl;
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl;
	}

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(string n, int a, char g, float c) {
		cout << "\nI am inside the parameterised constructor\n";
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	// setter member functions

	void setAge(int a) {
		age = a;
	}

	void setName(string n) {
		name = n;
	}

	void setGender(char g) {
		gender = g;
	}

	void setCredits(float c) {
		credits = c;
	}

	// getter member functions

	int getAge() {
		return age;
	}

	string getName() {
		return name;
	}

	char getGender() {
		return gender;
	}

	float getCredits() {
		return credits;
	}

};

int main() {

	customer c1("Aryan", 22, 'M', 10); // the parameterised constructor of the customer class
							           // will be invoked automatically to assign values
									   // to the data members of the customer object c2

	c1.printCustomerInfo();

	c1.setName("Avanish");

	cout << "\n" << c1.getName() << endl;

	return 0;
}