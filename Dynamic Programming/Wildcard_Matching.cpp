/*
Problem: LeetCode 44 – Wildcard Matching


Approach:
1. '?' matches single character.
2. '*' matches empty or multiple characters.
3. If characters match or '?'
      move diagonally.
4. If '*'
      take (match empty OR match one character).
5. dp[i][j] → whether p[0..i-1] matches s[0..j-1]
6. Base:
      dp[0][0] = true
      pattern can match empty only if all are '*'

Time Complexity: O(N * M)
Space Complexity:
Memoization → O(N * M)
Tabulation → O(N * M)
Space Optimized → O(M)
*/


// ======================= MEMOIZATION =======================

class Solution {
public:
    bool solve(int i, int j, string &p, string &s, vector<vector<int>> &dp) {

        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;

        if (j < 0 && i >= 0) {
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (p[i] == s[j] || p[i] == '?')
            return dp[i][j] = solve(i - 1, j - 1, p, s, dp);

        if (p[i] == '*')
            return dp[i][j] = solve(i - 1, j, p, s, dp) ||
                             solve(i, j - 1, p, s, dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, p, s, dp);
    }
};



// ======================= TABULATION =======================

class Solution {
public:
    bool isMatch(string s, string p) {

        int n = p.size();
        int m = s.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            bool allStars = true;
            for (int k = 1; k <= i; k++) {
                if (p[k - 1] != '*') {
                    allStars = false;
                    break;
                }
            }
            dp[i][0] = allStars;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};



// ======================= SPACE OPTIMISED =======================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        int n = p.size();
        int m = s.size();

        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;

        for (int i = 1; i <= n; i++) {

            bool allStars = true;
            for (int k = 1; k <= i; k++) {
                if (p[k - 1] != '*') {
                    allStars = false;
                    break;
                }
            }

            curr[0] = allStars;

            for (int j = 1; j <= m; j++) {

                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    curr[j] = prev[j - 1];
                }
                else if (p[i - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};
