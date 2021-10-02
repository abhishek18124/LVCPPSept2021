#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;

	cout << "Enter the value of n = ";
	cin >> n;

	int largest = INT_MIN;

	int i = 1; // loop variable
	int no;

	while(i <= n) {
		
		cout << "Enter a number = ";
		cin >> no;

		if(no > largest) {
			largest = no;
		}

		i = i + 1;
	}

	cout << "The largest number = " << largest << endl;

	return 0;
}