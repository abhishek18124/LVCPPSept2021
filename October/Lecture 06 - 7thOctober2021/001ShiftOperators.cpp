/*

Shift Operators

*/

#include<iostream>
#include<bitset>

using namespace std;

int main() {

	// Instead of shifting bits towards the left by 1 three times, 
	// you could've also shifted the bits to the left thrice in one go.

	int x = 10;

	cout << bitset<8>(x) << " : " << x << endl;

	x = (x<<1);
	cout << bitset<8>(x) << " : " << x << endl;
	
	x = (x<<1);
	cout << bitset<8>(x) << " : " << x << endl;
	
	x = (x<<1);
	cout << bitset<8>(x) << " : " << x << endl;

	cout << endl;

	// Instead of shifting bits towards the right by 1 three times, 
	// you could've also shifted the bits to the right thrice in one go.

	int y = 10;

	cout << bitset<8>(y) << " : " << y << endl;

	y = (y>>1);
	cout << bitset<8>(y) << " : " << y << endl;
	
	y = (y>>1);
	cout << bitset<8>(y) << " : " << y << endl;
	
	y = (y>>1);
	cout << bitset<8>(y) << " : " << y << endl;
	

	return 0;
}









