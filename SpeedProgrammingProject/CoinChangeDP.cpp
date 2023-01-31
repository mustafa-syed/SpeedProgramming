/*
Coin Change

Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
Note: Assume that you have an infinite supply of each type of coin.


Example 1:

Input:
sum = 4 ,
N = 3
coins[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
Sum = 10 ,
N = 4
coins[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5}
and {5,5}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array coins[ ] its size N and sum as input parameters and returns the number of ways to make change for given sum of money.


Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum)


Constraints:
1 <= sum, N <= 103
*/


#include<algorithm>
using namespace std;

long long int* DP;
long long int count(int coins[], int N, int sum) {

    sort(coins, coins + N);

    // code here.
    DP = new long long[sum + 1];

    DP[0] = 1;
    for (int i = 1; i < sum; i++)
        DP[i] = 0;



    for (int c = 0; c < N; c++) {
        for (int i = 0; i <= sum; i++) {
            if (i - coins[c] >= 0)
                DP[i] += DP[i - coins[c]];
        }
    }


    return DP[sum];
}