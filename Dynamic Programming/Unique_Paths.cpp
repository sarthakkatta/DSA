/*
Problem: LeetCode 62 – Unique Paths

Approach:
1. From any cell, robot can come only from top or left.
2. Use DP where dp[i][j] = paths from top + paths from left.
3. For memoization, use recursion + dp table.
4. For tabulation, fill dp grid iteratively.
5. For space optimization, keep only previous row.

Time Complexity: O(M * N)
Space Complexity:
Memoization → O(M * N)
Tabulation → O(M * N)
Space Optimized → O(N)
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////
// MEMOIZATION
//////////////////////////////////////////////////////////////

int f(int i, int j, vector<vector<int>>& dp) {

    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int uniquePathsMemo(int m, int n) {

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}

//////////////////////////////////////////////////////////////
// TABULATION
//////////////////////////////////////////////////////////////

int uniquePathsTab(int m, int n) {

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            if(i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

//////////////////////////////////////////////////////////////
// SPACE OPTIMIZED
//////////////////////////////////////////////////////////////

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++) {

            vector<int> curr(n, 0);

            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0)
                    curr[j] = 1;
                else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
                    curr[j] = up + left;
                }
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};
