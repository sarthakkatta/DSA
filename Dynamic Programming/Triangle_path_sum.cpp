/*
Problem: LeetCode 120 – Triangle

Approach:
1. Start from the bottom row of the triangle.
2. For each cell, you can move either directly down or diagonally down-right.
3. For every position, add its value to the minimum of those two choices.
4. Store results using DP so the same subproblems are not recomputed.
5. Memoization uses recursion + dp table.
6. Tabulation builds the answer bottom-up using a 2D dp array.
7. Space optimized version keeps only one row (the row below).

Final answer is stored at the top element after processing.

Time Complexity: O(N²)
Space Complexity:
Memoization → O(N²)
Tabulation → O(N²)
Space Optimized → O(N)
*/

                                      //MEMOIZATION :
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();

        // Base case: bottom row
        if(i == n - 1) return triangle[i][j];

        // Already computed
        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + f(i + 1, j, triangle, dp);
        int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, dp);
    }
};


                              //TABULATION :
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Copy last row into dp
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        // Fill from second last row upwards
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                int down = dp[i + 1][j];
                int diagonal = dp[i + 1][j + 1];
                dp[i][j] = triangle[i][j] + min(down, diagonal);
            }
        }

        return dp[0][0];
    }
};


                               //SPACE OPTIMISED :
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0);  // row below

        // Initialize with last row
        for(int j = 0; j < n; j++) {
            front[j] = triangle[n - 1][j];
        }

        // Fill from bottom-1 to top
        for(int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for(int j = 0; j <= i; j++) {
                int down = front[j];
                int diagonal = front[j + 1];
                curr[j] = triangle[i][j] + min(down, diagonal);
            }
            front = curr;  // move up
        }

        return front[0];
    }
};
