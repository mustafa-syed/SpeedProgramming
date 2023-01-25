//User function template for C++
/*

Nth catalan number

Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, � are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, �
Note: Positions start from 0 as shown above.

Example 1:

Input:
N = 5
Output: 42
Example 2:

Input:
N = 4
Output: 14
Your Task:
Complete findCatalan() function that takes n as an argument and returns the Nth Catalan number. The output is printed by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 100

*/

//Function to find the nth catalan number
#include<boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;

cpp_int findCatalan(int n)
{
    //code here
    if (n == 0)
        return 1;
    else {
        vector<cpp_int> cat;
        cat.push_back(1);

        for (int i = 0; i < n; i++) {
            cpp_int num = (2 * (2 * i + 1) * cat[i]) / (i + 2);
            cat.push_back(num);
        }


        return cat[n];
    }
}
