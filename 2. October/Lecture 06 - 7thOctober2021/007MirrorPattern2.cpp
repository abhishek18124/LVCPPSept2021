/*

Write a program to print the following pattern

   *
  ***
 *****
*******
 *****
  ***
   *

here, n i.e. number of rows with increasing pattern is equal to four.

*/

#include<iostream>

using namespace std;

int main() {

   int n = 4;

   // upper part of the pattern

   for(int i=1; i<=n; i++) {
      // in the ith row, we have (n-i) spaces
      for(int j=1; j<=n-i; j++) {
         cout << " ";
      }

      // followed by 2*i-1 stars
      for(int j=1; j<=2*i-1; j++) {
         cout << "*";
      }

      cout << endl;

   }

   // lower part

   for(int i=1; i<n; i++) {
      // in the ith row, we have i spaces
      for(int j=1; j<=i; j++) {
         cout << " ";
      }

      // followed by 2*(n-i)-1 stars
      for(int j=1; j<=2*(n-i)-1; j++) {
         cout << "*";
      }

      cout << endl;
   }

	return 0;
}