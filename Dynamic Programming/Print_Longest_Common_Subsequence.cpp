/*
Problem: Print Longest Common Subsequence

Approach:
1. Build LCS length DP table using tabulation.
2. dp[i][j] stores LCS length for prefixes text1[0..i-1], text2[0..j-1].
3. If characters match, move diagonally and include character.
4. If not, move in direction of larger DP value (up or left).
5. Reconstruct LCS by backtracking from dp[n][m].
6. Reverse the collected characters to get final LCS string.

Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/

// Solution class for LCS with reconstruction using tabulation
class Solution {
public:
    // Function to return the LCS string of text1 and text2
    string longestCommonSubsequence(string &text1, string &text2) {
        int n = text1.size();
        int m = text2.size();

        // Create DP table to store lengths of LCS for all substrings
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill dp table bottom-up
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Reconstruct LCS string from dp table
        int i = n, j = m;
        string lcs = "";

        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                lcs += text1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};
