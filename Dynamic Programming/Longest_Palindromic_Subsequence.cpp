/*
Problem: LeetCode 516 – Longest Palindromic Subsequence

Approach:
1. A palindrome reads same forward and backward.
2. Reverse the string.
3. Compute LCS between original string and reversed string.
4. The LCS length gives the longest palindromic subsequence.
5. Use tabulation DP for LCS computation.

Time Complexity: O(N²)
Space Complexity: O(N²)
*/

class Solution {
public:
    int lcs(string s, string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1, 0));

        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]) 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return lcs(s, t);
    }
};
