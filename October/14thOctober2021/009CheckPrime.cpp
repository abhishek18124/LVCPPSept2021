#include<iostream>

using namespace std;

void printAllPrimes(int);
bool isPrime(int);

int main() {

	int N = 10;

	printAllPrimes(N);

	return 0;
}

void printAllPrimes(int N) {
	// prints all the prime numbers from 2 to N
	for(int n=2; n<=N; n++) {
		// check if n is prime or not
		if(isPrime(n)) {
			cout << n << " ";
		}
	}

	cout << endl;
}

bool isPrime(int n) {
	for(int i=2; i<n; i++) {
		if(n%i == 0) {
			// n is not prime
			return false;
		}
	}
	// n is prime
	return true;
}
