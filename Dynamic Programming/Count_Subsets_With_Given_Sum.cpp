/*
Problem: Count Subsets With Given Sum

Approach:
1. For each element, either include it in subset or skip it.
2. Use DP where dp[i][s] stores number of subsets using first i elements having sum = s.
3. Base case: sum 0 is always possible (empty subset).
4. Add counts from take + notTake choices.
5. Memoization uses recursion + dp table.
6. Tabulation builds dp iteratively.
7. Space optimized version keeps only previous row.

Time Complexity: O(N * K)
Space Complexity:
Memoization → O(N * K)
Tabulation → O(N * K)
Space Optimized → O(K)
*/

                                                                                   //MEMOIZATION SOLN :
int f(int ind, int sum, vector<int> &num, vector<vector<int>> &dp) {
    if (sum == 0) return 1; // sum 0 achieved
    if (ind == 0) return num[0] == sum ? 1 : 0; // only first element left to consider
    
    if (dp[ind][sum] != -1) return dp[ind][sum];

    int notTake = f(ind-1, sum, num, dp);
    int take = 0;
    if (num[ind] <= sum) 
        take = f(ind-1, sum - num[ind], num, dp);

    return dp[ind][sum] = notTake + take;
}

int findWays(vector<int> &num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    return f(n-1, tar, num, dp);
}


                                                                                      //TABULATION SOLN :
int findWays(vector<int> &num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));

    // base case: sum 0 can always be formed by empty subset
    for (int i = 0; i < n; i++) dp[i][0] = 1;

    // base case: first element alone can form num[0] if <= target
    if (num[0] <= tar) dp[0][num[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        for (int sum = 0; sum <= tar; sum++) {
            int notTake = dp[ind-1][sum];
            int take = 0;
            if (num[ind] <= sum) take = dp[ind-1][sum - num[ind]];
            dp[ind][sum] = notTake + take;
        }
    }

    return dp[n-1][tar];
}


                                                                              //SPACE OPTIMISED SOLN :
int findWays(vector<int> &num, int tar) {
    int n = num.size();
    vector<int> prev(tar+1, 0), curr(tar+1, 0);

    prev[0] = 1;
    if (num[0] <= tar) prev[num[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        curr[0] = 1;
        for (int sum = 1; sum <= tar; sum++) {
            int notTake = prev[sum];
            int take = 0;
            if (num[ind] <= sum) take = prev[sum - num[ind]];
            curr[sum] = notTake + take;
        }
        prev = curr;
    }

    return prev[tar];
}
