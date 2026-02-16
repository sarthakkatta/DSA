/*
Problem: Matrix Chain Multiplication


Approach:
1. Try all possible partitions between i and j.
2. Cost = multiplication cost + left part + right part.
3. Take minimum among all partitions.
4. dp[i][j] → minimum cost to multiply matrices from i to j.
5. Base:
      if i == j → cost = 0.

Time Complexity: O(N * N * N)
Space Complexity:
Memoization → O(N * N)
Tabulation → O(N * N)
*/


// ======================= MEMOIZATION =======================

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &arr,
      vector<vector<int>>& dp){

    if(i == j) return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;

    for(int k = i; k < j; k++){

        int steps =
            arr[i-1] * arr[k] * arr[j]
            + f(i, k, arr, dp)
            + f(k + 1, j, arr, dp);

        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));

    return f(1, N-1, arr, dp);
}




// ======================= TABULATION =======================

#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr, int N) {

    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = N - 1; i >= 1; i--) {

        for (int j = i + 1; j < N; j++) {

            int mini = 1e9;

            for (int k = i; k < j; k++) {

                int steps =
                    arr[i - 1] * arr[k] * arr[j]
                    + dp[i][k]
                    + dp[k + 1][j];

                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
}
