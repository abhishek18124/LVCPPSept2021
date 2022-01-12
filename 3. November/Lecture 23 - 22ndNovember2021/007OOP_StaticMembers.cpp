#include<iostream>
#include<cstring>

using namespace std;

class customer {
public :
	int age;
	string name; // member object
	static int count; // shared by all the class objects
	
	void printCustomerInfo() {
		cout << "\nCustomer Information\n" << endl;
		cout << "Name : " << this->name << endl;
		cout << "Age : " << this->age << endl;
	}

	// here, I have overridden the implementation for the default constructor
	customer() {
		// cout << "\nI am inside the default constructor of customer\n";
		count++;
	}

	static int getCount() {
		return count;
	}
};

int customer::count = 0; // initialsation of static data member

int main() {

	customer c1;
	customer c2;
	customer c3;
	customer c4;
	customer c5;

	cout << customer::count << " "; // since count is a static member of the class
								     // you can use the class name to access it

	cout << customer::getCount() << endl; // since count is a static member of the class
								     // you can use the class name to access it


	cout << c1.count << " " << c1.getCount() << endl;
	cout << c2.count << endl;
	cout << c3.count << endl;
	cout << c4.count << endl;
	cout << c5.count << endl;
	
	return 0;
}