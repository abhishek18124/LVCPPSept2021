#include<iostream>
#define PI 3.14
#define PRINT cout << 
#define NEWLINE endl
#define SEMICOLON ;
#define F(n) for(int i=1; i<=n; i++) {PRINT i << " " SEMICOLON}

using namespace std;

int main() {


	int r = 2;

	PRINT 2 * PI * r << NEWLINE SEMICOLON

	F(10)

	PRINT NEWLINE;

	return 0;
}