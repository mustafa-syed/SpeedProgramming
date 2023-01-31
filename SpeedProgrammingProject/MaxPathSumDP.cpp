/*

Maximum path sum in matrix

Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

NOTE: We can start from any column in zeroth row and can end at any column in (N-1)th row.

Example 1:

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. It gives the sum = 1009.

Example 2:

Input: N = 2
Matrix = {{2, 2},
          {2, 2}}
Output: 4
Explaination: No matter which path is chosen, the output is 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maximumPath() which takes the size N and the Matrix as input parameters and returns the highest maximum path sum.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
1 <= N <= 500
1 <= Matrix[i][j] <= 1000

*/

#include<algorithm>
#include<vector>
using namespace std;

int maximumPathDP(int N, vector<vector<int>> Matrix);

int Sum[500][500];
int maximumPath(int N, vector<vector<int>> Matrix)
{
    // code here
    memset(Sum, -1, sizeof(Sum));
    for (int i = 0; i < N; i++)
        Sum[0][i] = Matrix[0][i];

    int maxSum = -1;
    /*for(int i = 0; i < N; i++){
            maxSum = max( maximumPathDP( N, Matrix, N-1, i), maxSum);
    }*/

    maxSum = maximumPathDP(N, Matrix);

    return maxSum;

}


/*int maximumPathDP(int N, vector<vector<int>> Matrix, int r, int c){

    if( r < 0 or c < 0 or c > N-1)
        return -1;

    if( Sum[r][c] != -1)
        return Sum[r][c];


    int mp1 = maximumPathDP( N, Matrix, r-1, c-1);
    int mp2 = maximumPathDP( N, Matrix, r-1, c);
    int mp3 = maximumPathDP( N, Matrix, r-1, c+1);

    Sum[r][c] = Matrix[r][c] + max( max( mp1, mp2 ), mp3);

    return Sum[r][c];
}*/

int maximumPathDP(int N, vector<vector<int>> Matrix) {

    for (int r = 1; r < N; r++) { // filling all rows from 1 to N-1
        for (int c = 0; c < N; c++) {
            int maxSum = 0;
            if (c != 0)
                maxSum = Sum[r - 1][c - 1];

            if (maxSum < Sum[r - 1][c])
                maxSum = Sum[r - 1][c];

            if (c < N - 1 && maxSum < Sum[r - 1][c + 1])
                maxSum = Sum[r - 1][c + 1];

            Sum[r][c] = maxSum + Matrix[r][c];
        }

    }

    int maxSum = 0;
    for (int c = 0; c < N; c++) {
        if (maxSum < Sum[N - 1][c])
            maxSum = Sum[N - 1][c];
    }

    return maxSum;


}