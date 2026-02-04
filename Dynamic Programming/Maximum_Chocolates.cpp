/*
Problem: Maximum Chocolates (Coding Ninjas / Striver DP – Chocolate Pickup)

Approach:
1. Two robots start at top row: one at column 0, other at column m-1.
2. At each row, both robots can move to left, right, or stay (3 choices each).
3. For every (row, col1, col2), collect chocolates from both positions.
4. If both land on same cell, count chocolate only once.
5. Try all 3×3 move combinations and take maximum.
6. Use DP to avoid recomputation.
7. Space optimized version keeps only next row.

Time Complexity: O(N * M * M * 9)
Space Complexity:
Memoization → O(N * M * M)
Tabulation → O(N * M * M)
Space Optimized → O(M * M)
*/

                                //MEMOIZATION:
#include <bits/stdc++.h> 
int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    int n = grid.size();
    int m = grid[0].size();
    if(j1 < 0 || j2 < 0 || j1 >=m || j2 >= m) return -1e9;
    if(i == n-1){
        if(j1 == j2){
            return grid[i][j1];
        }else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;

    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int value;

            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];

            value += f(i + 1, j1 + dj1, j2 + dj2, grid, dp);
            maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c-1, grid, dp);
}


                                //TABULATION:
#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int n, int m, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {

                int maxi = INT_MIN;

                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int new_j1 = j1 + dj1;
                        int new_j2 = j2 + dj2;

                        if (new_j1 >= 0 && new_j1 < m && new_j2 >= 0 && new_j2 < m) {
                            int value = 0;

                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            value += dp[i + 1][new_j1][new_j2];
                            maxi = max(maxi, value);
                        }
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m - 1];
}


                                 //SPACE OPTIMISED:
#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int n, int m, vector<vector<int>>& grid) {
    vector<vector<int>> front(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

    // Base case: last row
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // From n-2 to 0
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;

                // All 3 x 3 possible moves
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int new_j1 = j1 + dj1;
                        int new_j2 = j2 + dj2;

                        if (new_j1 >= 0 && new_j1 < m && new_j2 >= 0 && new_j2 < m) {
                            int value = 0;
                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            value += front[new_j1][new_j2];
                            maxi = max(maxi, value);
                        }
                    }
                }

                curr[j1][j2] = maxi;
            }
        }
        front = curr; // move up
    }

    return front[0][m - 1];
}
