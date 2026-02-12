/*
Problem: LeetCode 72 – Edit Distance

Approach:
1. If characters match → move diagonally.
2. If not match → take min of Insert, Delete, Replace.
3. dp[i][j] → operations to convert word1[0..i-1] to word2[0..j-1]
4. Base:
      dp[i][0] = i
      dp[0][j] = j
5. Space optimized using two 1D arrays.

Time Complexity: O(N * M)
Space Complexity:
Memoization → O(N * M)
Tabulation → O(N * M)
Space Optimized → O(M)
*/


// ======================= MEMOIZATION =======================

class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {

        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        }

        int insertOp  = solve(i, j - 1, word1, word2, dp);
        int deleteOp  = solve(i - 1, j, word1, word2, dp);
        int replaceOp = solve(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, word1, word2, dp);
    }
};



// ======================= TABULATION =======================

class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1],
                                       min(dp[i - 1][j],
                                           dp[i - 1][j - 1]));
                }
            }
        }

        return dp[n][m];
    }
};



// ======================= SPACE OPTIMISED =======================

class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.size(), m = word2.size();
        vector<int> prev(m + 1), curr(m + 1);

        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {

            curr[0] = i;

            for (int j = 1; j <= m; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + min(curr[j - 1],
                                      min(prev[j], prev[j - 1]));
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};
