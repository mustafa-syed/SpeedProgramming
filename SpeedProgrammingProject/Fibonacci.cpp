/*

Nth Fibonacci Number

Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

Example 1:

Input: n = 2
Output: 1
Explanation: 1 is the 2nd number
of fibonacci series.
Example 2:

Input: n = 5
Output: 5
Explanation: 5 is the 5th number
of fibonacci series.

Your Task:
You dont need to read input or print anything. Complete the function nthFibonacci() which takes n as input parameter and returns nth fibonacci number.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1<= n <=1000

*/
#include<vector>
using namespace std;

// User function Template for C++
long long int nthFibonacci(long long int n) {
    // code here
    //if(n <= 2)
    //    return 1;

    vector<long long int> fib;
    fib.push_back(1);
    fib.push_back(1);
    for (int i = 2; i < n; i++) {
        fib.push_back((fib[i - 1] + fib[i - 2]) % 1000000007);
    }

    return fib[n - 1];
}
