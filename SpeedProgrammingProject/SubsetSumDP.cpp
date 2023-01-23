// ref: https://stackoverflow.com/questions/4632322/finding-all-possible-combinations-of-numbers-to-reach-a-given-sum

/*
Subset Sum Problem
MediumAccuracy : 32.0 % Submissions : 109K + Points : 4
Given an array of non - negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

Example 1:

Input:
N = 6
arr[] = { 3, 34, 4, 12, 5, 2 }
sum = 9
Output : 1
Explanation : Here there exists a subset with
sum = 9, 4 + 3 + 2 = 9.
Example 2 :

Input :
N = 6
arr[] = { 3, 34, 4, 12, 5, 2 }
sum = 30
Output : 0
Explanation : There is no subset with sum 30.

Expected Time Complexity : O(sum * N)
Expected Auxiliary Space : O(sum * N)

Constraints :
    1 <= N <= 100
    1 <= arr[i] <= 100
    1 <= sum <= 105
*/


#include<vector>
#include<numeric>

using namespace std;

int dp[100][10000];
bool SubsetCheck(vector<int> arr, int n, int sum);

bool isSubsetSum(vector<int> arr, int sum) {
    memset(dp, -1, sizeof(dp)); // initialize the array to -1
    return SubsetCheck(arr, arr.size(), sum); // calling the recursive DP function to generate sum of all permutations

    // call to recursive solution
    //return SubsetCheck( arr, sum, arr.begin()); // calling the recursive DP function to generate sum of all permutations
}

/* Recursive approach that exceeds the time limit
bool SubsetCheck(vector<int> &arr, int sum, vector<int>::iterator i, int partial_sum=0 ){ // orig array, sum to match, items in the permutation

    if(partial_sum == sum){ // base case 1: if sum is equal to required sum
        return true; // break the further recursive cases
    }
    if( partial_sum > sum or i == arr.end() ) // base case 2: if the sum exceeds the required sum
        return false;

    for( ; i < arr.end(); i++){ // next recursive case
        int elem = *i; // starting point of the permutation

        bool res = SubsetCheck( arr, sum, i+1, partial_sum+elem ); // next call
        if( res == true )
            return true;
    }
    return false;

}*/

// memoization (top-down recursion) technique
bool SubsetCheck(vector<int> arr, int n, int sum) {

    if (sum == 0) // if sum is zero then return true (base case)
        return true;

    if (n <= 0) // if array size is zero but sum is not zero then return false (base case)
        return false;

    if (dp[n - 1][sum] != -1) // if the result is already available then return it (memoization)
        return dp[n - 1][sum];

    if (arr[n - 1] > sum) { // if the current value is greater than sum then we do not include it
        dp[n - 1][sum] = SubsetCheck(arr, n - 1, sum);
    }
    else { // if the current value is less than sum then we will check both cases - include or exclude this value
        dp[n - 1][sum] = SubsetCheck(arr, n - 1, sum) or SubsetCheck(arr, n - 1, sum - arr[n - 1]);
    }

    return dp[n - 1][sum];
}
