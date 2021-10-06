#include<iostream>
#include<bitset>

using namespace std;

int main() {

	int x = 12;
	int y = 15;

	cout << bitset<5>(x) << " : " << x << endl;
	cout << bitset<5>(y) << " : " << y << endl;
	cout << bitset<5>(x&y) << " : " << (x&y) << endl;

	cout << endl;

	cout << bitset<5>(x) << " : " << x << endl;
	cout << bitset<5>(y) << " : " << y << endl;
	cout << bitset<5>(x|y) << " : " << (x|y) << endl;

	cout << endl;

	cout << bitset<5>(x) << " : " << x << endl;
	cout << bitset<5>(y) << " : " << y << endl;
	cout << bitset<5>(x^y) << " : " << (x^y) << endl;

	cout << endl;
	
	int z = 10;
	cout << bitset<32>(z) << " : " << z << endl;
	cout << bitset<32>(~z) << " : " << (~z) << endl;


	return 0;
}