/*
	
	Vectors Part II
	
	How to create a vector ? 
		> use fill constructor
		> use range constructor
		> use copy constructor
		> use initialiser list (C++11)
	How to add elements to a vector ?
	    > use vector::insert
	      > single element
	      > fill
	      > range
	      > initialiser list
	How to remove elements from a vector ?
	    > use vector::erase
	      > single element
	      > range

	How to sort a vector ?
      > use built-in comparator
      > use user-defined comparator
      > pass in reverse order

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	// int n;
	// cin >> n;

	int n = 10; // can be specified at compile-time or run-time

	vector<int> v1(n, 0); // invokes the parameterised constructor of 
					      // the vector<int> class to create a vector
					      // of size n

	cout << v1.size() << " " << v1.capacity() << endl;

	for(int i=0; i<v1.size(); i++) {
		cout << v1[i] << " "; // v1.operator[](i);
	}

	cout << endl;

	vector<int> v2(v1); // invokes the copy constructor to construct v2 as a copy of v1
	
	vector<int> v3;
	v3 = v1; // invokes the copy assignment operator to construct v3 as a copy of v1
	
	vector<int> v4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	vector<int> v5(v4.begin()+2, v4.end()-1);

	for(auto x  : v5) {
		cout << x << " ";
	}

	cout << endl;

	int x = 10;
	int y = 20;

	vector<vector<int>> v6(x, vector<int>(y, 100));

	for(int i=0; i<x; i++) {
		for(int j=0; j<y; j++) {
			cout << v6[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;


	return 0;
}






