/*
Ugly Numbers
Difficulty Level : Medium

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included.
Given a number n, the task is to find n’th Ugly number.

Examples:

Input  : n = 7
Output : 8

Input  : n = 10
Output : 12

Input  : n = 15
Output : 24

Input  : n = 150
Output : 5832
*/

#include<iostream>
using namespace std;

int PrimeFactorize(int x, int n) {
	while (x % n == 0)
		x /= n;

	return x;
}

bool isUgly(int x) {
	x = PrimeFactorize(x, 2); // the sequecne of factorization is not important here
	x = PrimeFactorize(x, 3);
	x = PrimeFactorize(x, 5);

	return (x == 1) ? true : false;	
}

int UglyNumbersBasic(int n) {
	// use naive approach to keep finding all ugly numbers until the nth number is reached.
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;

	int i = 2;
	while (true) {
		if ( isUgly(i) ) {
			n--;
			if (n == 1)
				return i;
		}
		i++;
	}
}

#include<vector>
int UglyNumbersDynamicProgramming(int n) {
	vector<int> ugly;

	ugly.push_back( 1 ); // first ugly term
	int i2, i3, i5;
	i2 = i3 = i5 = 0; // all terms are generated with ugly[0]
	// multiply each term of ugly series with 2, 3, and 5 
	// to get new ugly numbers
	int next_term_with_2 = ugly[i2] * 2;
	int next_term_with_3 = ugly[i3] * 3;
	int next_term_with_5 = ugly[i5] * 5;

	// calculate 2 to n values
	for (int i = 0; i < n-1; i++) {
		int next_term = min(next_term_with_2, 
			min(next_term_with_3 , next_term_with_5));

		ugly.push_back(next_term);

		// calculate next term for respective multiple(s)
		if (next_term == next_term_with_2) {
			i2++;
			next_term_with_2 = ugly[i2]*2;
		} // no else here cos the current term can be a multiple of 2, 3, and 5
		if (next_term == next_term_with_3) {
			i3++;
			next_term_with_3 = ugly[i3]*3;
		} // no else here cos the current term can be a multiple of 2, 3, and 5
		if (next_term == next_term_with_5) {
			i5++;
			next_term_with_5 = ugly[i5]*5;
		}		
	}

	return ugly.back();
}