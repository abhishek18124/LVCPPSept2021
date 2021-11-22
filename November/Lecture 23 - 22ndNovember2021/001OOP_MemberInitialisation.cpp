#include<iostream>
#include<cstring>

using namespace std;

class creditCard {
	string cardNumber;
	int cvv;

public:

	creditCard() {
		cout << "\nI am inside the default constructor of creditCard\n";
	}

	creditCard(string cn, int n) {
		cout << "\nI am inside the parameterised constructor of creditCard\n";
		cardNumber = cn;
		cvv = n;
	}

	void setCardNumber(string cn) {
		cardNumber = cn;
	}

	void setCVV(int n) {
		cvv = n;
	}

	string getCardNumber() {
		return cardNumber;
	}

	int getCVV() {
		return cvv;
	}
};

class customer {
public :
	int age;
	string name; // member object
	creditCard card; // member object

	void printCustomerInfo() {
		cout << "\nCustomer Information\n" << endl;
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Card Number : " << card.getCardNumber() << endl;
		cout << "CVV : " << card.getCVV() << endl;
	}

	// here, I have overridden the implementation for the default constructor
	customer() {
		cout << "\nI am inside the default constructor\n";
	}

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(string n, int a) : name(n), age(a) {
		cout << "\nI am inside the parameterised constructor of customer\n";
		// name = n; // string object is first default constructed
		// 		  // and then assigned the value n
	}

	// here, I am implementing a parameterised constructor to assign values
	// to the data members of an object when it declared
	customer(string n, int a, string cn, int cv) : name(n), age(a), card(cn, cv) {
		cout << "\nI am inside the parameterised constructor of customer\n";
		// name = n; // string object is first default constructed
		// 		  // and then assigned the value n
		// card.setCardNumber(cn);
		// card.setCVV(cv);
	}

	void setCardInfo(string cn, int n) {
		card.setCardNumber(cn);
		card.setCVV(n);
	}
};

int main() {
	

	customer c1("Avanish", 20); // the parameterised constructor of the customer class
							         // will be invoked automatically to assign values
									 // to the data members of the customer object c1

	c1.setCardInfo("1234-4567", 123);

	c1.printCustomerInfo();

	customer c2("Aryan", 21, "9999-1234", 921);

	c2.printCustomerInfo();

	return 0;
}