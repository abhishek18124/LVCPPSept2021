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

} c3 ;


// void printCustomerInfo(customer c) {
// 	cout << "\nCustomer Information\n" << endl;
// 	cout << "Name : " << c.name << endl;
// 	cout << "Age : " << c.age << endl;
// 	cout << "Gender : " << c.gender << endl;
// 	cout << "Credits : " << c.credits << endl;
// }

int main() {

	customer c1; // object declaration i.e. memory is allocated to 
			     // to store the data members of customer object c1

	c1.age = 20;
	c1.gender = 'F';
	c1.credits = 0;
	strcpy(c1.name, "Shrutika");

	// cout << "\nCustomer Information\n" << endl;
	// cout << "Name : " << c1.name << endl;
	// cout << "Age : " << c1.age << endl;
	// cout << "Gender : " << c1.gender << endl;
	// cout << "Credits : " << c1.credits << endl;

	// printCustomerInfo(c1);

	c1.printCustomerInfo();

	customer c2; // object declaration

	strcpy(c2.name, "Hemangi");
	c2.gender = 'F';
	c2.credits = 100;
	c2.age = 21;

	// cout << "\nCustomer Information\n" << endl;
	// cout << "Name : " << c2.name << endl;
	// cout << "Age : " << c2.age << endl;
	// cout << "Gender : " << c2.gender << endl;
	// cout << "Credits : " << c2.credits << endl;

	// printCustomerInfo(c2);

	c2.printCustomerInfo();

	c3.credits = 500;
	strcpy(c3.name, "Shivam");
	c3.gender = 'M';
	c3.age = 21;

	c3.printCustomerInfo();

	return 0;
}