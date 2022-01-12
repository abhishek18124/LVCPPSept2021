#include<iostream>

using namespace std;

int main() {

	int* ptr = new int; // allocate 4B of memory on the heap segment
			            // and returns the starting address i.e. the address
			            // of the 1B of memory allocated to store an integer


	*ptr = 50;

	cout << "*ptr = " << *ptr << endl;

	cout << ptr << endl;

	delete ptr; // deallocates/frees 4B of memory allocated
			    // to store an integer

	ptr = NULL; // for safety to ensure you do not try to 
			    // dereference memory which has been already
				// released

	cout << *ptr << endl;

	// ptr = new int;

	// delete ptr;

	return 0;
}