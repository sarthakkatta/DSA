/*
Problem: LeetCode 1312 – Minimum Insertion Steps to Make a String Palindrome

Approach:
1. Minimum insertions needed = N - Longest Palindromic Subsequence (LPS).
2. LPS can be found by computing LCS between string and its reverse.
3. Build DP table for LCS using tabulation.
4. Subtract LPS length from string length to get answer.

Time Complexity: O(N²)
Space Complexity: O(N²)
*/

class Solution {
public:

int lcs(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s , t);
}

int minInsertions(string s) {
    return s.size() - longestPalindromeSubsequence(s);
}

};
