/*
Problem: LeetCode 115 – Distinct Subsequences


Approach:
1. Count number of ways string t appears as a subsequence in s.
2. If characters match:
      take both match + skip current character in s.
3. If not match:
      skip current character in s.
4. DP state:
      dp[i][j] → ways to form t[0..j-1] using s[0..i-1]
5. Base case:
      dp[i][0] = 1 (empty string always possible)
6. Space optimized to 1D by iterating j backwards.

Time Complexity: O(N * M)
Space Complexity:
Memoization → O(N * M)
Tabulation → O(N * M)
Space Optimized → O(M)
*/
                                MEMOIZATION:
class Solution {
private:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = f(i - 1, j - 1,s,t,dp) + f(i - 1, j, s,t,dp);
        }else{
            return dp[i][j] = f(i - 1, j, s,t,dp);
        }
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n -1, m - 1, s, t, dp);
    }
};


                                     //TABULATION:
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        for(int i =0; i<=n; i++) dp[i][0] = 1;
        for(int j = 1; j <=m;j++) dp[0][j] = 0;//this line is not compulsory becoz the dp is initialised with 0 so it handles this case
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= m; j++){
                if(s[i - 1] == t[j - 1]){
                        dp[i][j] = dp[i - 1][j- 1] + dp[i - 1][j];
                }else{
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};


                                       //SPACE OPTIMISED TO 2D ARRAY:
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m + 1, 0), curr(m + 1, 0);
        prev[0]=curr[0]=1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= m; j++){
                if(s[i - 1] == t[j - 1]){
                        curr[j] = prev[j- 1] + prev[j];
                }else{
                        curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};



                               //SPACE OPTIMISED TO 1D ARRAY:
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m + 1, 0);
        prev[0]=1;
        for(int i = 1; i <= n; i++){
            for(int j = m; j>= 1; j--){
                if(s[i - 1] == t[j - 1]){
                        prev[j] = prev[j- 1] + prev[j];
                }
            }
        }
        return (int)prev[m];
    }
};
