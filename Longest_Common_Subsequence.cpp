/*
Problem: LeetCode 1143 – Longest Common Subsequence

Approach:
1. Compare characters of both strings from left to right.
2. If characters match, include it and move diagonally.
3. If not, take maximum by skipping one character from either string.
4. Use DP where dp[i][j] stores LCS length till s1[0..i], s2[0..j].
5. Memoization avoids recomputation using recursion.
6. Tabulation fills DP table bottom-up.
7. Space optimized version keeps only previous row.

Time Complexity: O(N * M)
Space Complexity:
Memoization → O(N * M)
Tabulation → O(N * M)
Space Optimized → O(M)
*/

//////////////////////////////////////////////////////////////////////
// MEMOIZATION
//////////////////////////////////////////////////////////////////////

class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
        
        return dp[i][j] = max(
            f(i - 1, j, s1, s2, dp),
            f(i, j - 1, s1, s2, dp)
        );
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s1, s2, dp);
    }
};

//////////////////////////////////////////////////////////////////////
// TABULATION
//////////////////////////////////////////////////////////////////////

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

//////////////////////////////////////////////////////////////////////
// SPACE OPTIMISED
//////////////////////////////////////////////////////////////////////

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};
