/*
Problem: Longest Common Substring

Approach:
1. Use DP where dp[i][j] stores length of longest common substring
   ending at s[i-1] and t[j-1].
2. If characters match, extend previous substring (diagonal).
3. If characters don’t match, reset current length to 0.
4. Track maximum value during DP computation.
5. Space optimized version uses only two rows.

Time Complexity: O(N * M)
Space Complexity:
Tabulation → O(N * M)
Space Optimized → O(M)
*/

                                      //TABULATION:
int lcs(string &s, string &t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}


                                      //SPACE OPTIMISED:
int lcs(string &s, string &t) {
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0); 
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return ans;
}
