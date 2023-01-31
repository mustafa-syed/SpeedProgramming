/*
Edit Distance

Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.


Example 1:
Input:
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required inserting 's' between two 'e's of str1.

Example 2:
Input :
s = "gfg", t = "gfg"
Output:
0
Explanation: Both strings are same.


Your Task:
You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and returns the minimum number of operation to convert the string s to string t.


Expected Time Complexity: O(|s|*|t|)
Expected Space Complexity: O(|s|*|t|)


Constraints:
1 <= Length of both strings <= 100
Both the strings are in lowercase
*/
#include<iostream>
using namespace std;

// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return std::min(std::min(x, y), z); }

int editDistance(string s, string t) {
    // Code here
    int m = s.length();
    int n = t.length();

    if (m == 0)
        return n;

    if (n == 0)
        return m;

    int** dp;
    dp = new int* [m + 1];
    for (int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j; // add j characters in s
            else if (j == 0)
                dp[i][j] = i; // remove i characters from s
            else if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // no added cost here
            }
            else {
                dp[i][j] = 1 + // one change required
                    min(
                        dp[i][j - 1], // add a character
                        dp[i - 1][j - 1], // replace a character
                        dp[i - 1][j] // delete a character
                    );
            }
        }
    }
    return dp[m][n];
}