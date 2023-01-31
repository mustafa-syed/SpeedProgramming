/*
Append for OR

Problem: https://www.codechef.com/problems/APPENDOR?tab=statement
Chef has an array A of length N.

Chef wants to append a non-negative integer X to the array A such that the bitwise OR of the entire array becomes =Y i.e. (A1 | A2 | … An | X) = Y). (Here, | denotes the bitwise OR operation)

Determine the minimum possible value of X. If no possible value of X exists, output -1.
*/

#include <iostream>
using namespace std;

int appendOr() {
	// your code goes here
	int K;
	cin >> K;
	while (K > 0) {

		int n, y;
		cin >> n >> y;
		int a, bitWiseOR = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			bitWiseOR = bitWiseOR | a;
		}

		bool cont = true;
		for (int j = 0; j <= y and cont; j++) {
			if ((bitWiseOR | j) == y) {
				cout << j << endl;
				cont = false;
			}
		}
		
		if (cont == true)
			cout << -1 << endl;

		K--;
	}
	return 0;
}
