#include<iostream>
#include<cstring>

using namespace std;

class customer {
public :
	int age;
	string name; // member object
	static int count; // shared by all the class objects
	const int id;
	
	void printCustomerInfo() const {
		cout << "\nCustomer Information\n" << endl;
		cout << "Name : " << this->name << endl;
		cout << "Age : " << this->age << endl;
		cout << "Id : " << this->id << endl;
	}

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(string name, int age, int id) : id(id)  {
		cout << "\nI am inside the parameterised constructor of customer\n";
		count++;
		this->name = name;
		// this->id = id; // error
		this->age = age;
	}

	static int getCount() {
		return count;
	}

	int getAge() const {
		return this->age;
	}

	string getName() const {
		return this->name;
	}

	int getId() const {
		return this->id;
	}
};

int customer::count = 0; // initialsation of static data member

int main() {

	customer c1("Nilabh", 22, 99);

	c1.printCustomerInfo();

	// cout << "Name : " << c1.getName() << endl;
	// cout << "Age : " << c1.getAge() << endl;
	// cout << "Id : " << c1.getId() << endl; 
	
	return 0;
}