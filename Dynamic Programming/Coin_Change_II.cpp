/*
Problem: LeetCode 518 – Coin Change II

Approach:
1. We need to count number of ways to make the given amount.
2. For each coin, we can either take it (stay on same index) or skip it.
3. Order does not matter, so we process coins one by one.
4. DP state: dp[i][t] = ways to make sum t using coins[0..i].
5. Memoization uses recursion.
6. Tabulation builds DP table bottom-up.
7. Space optimized version uses only one array.

Time Complexity: O(N * Amount)
Space Complexity:
Memoization → O(N * Amount)
Tabulation → O(N * Amount)
Space Optimized → O(Amount)
*/

////////////////////////////////////////////////////////////
// MEMOIZATION (UNCHANGED)
////////////////////////////////////////////////////////////

class Solution {
public:
    int f(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(i == 0){
            return (target % coins[0] == 0) ? 1 : 0;
        }
        if(dp[i][target] != -1) return dp[i][target]; 

        int nottake = f(i - 1, target, coins, dp);
        int take = 0;
        if(coins[i] <= target) 
            take = f(i, target - coins[i], coins, dp);

        return dp[i][target] = nottake + take;
    } 

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};

////////////////////////////////////////////////////////////
// TABULATION
////////////////////////////////////////////////////////////

class SolutionTab {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case
        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0)
                dp[0][t] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int t = 0; t <= amount; t++){
                int notTake = dp[i - 1][t];
                int take = 0;
                if(coins[i] <= t)
                    take = dp[i][t - coins[i]];

                dp[i][t] = notTake + take;
            }
        }

        return dp[n - 1][amount];
    }
};

////////////////////////////////////////////////////////////
// SPACE OPTIMISED
////////////////////////////////////////////////////////////

long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<long> prev(T + 1, 0);

    // Base case: using only the first coin
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = 1;
    }

    for (int ind = 1; ind < n; ind++) {
        vector<long> cur(T + 1, 0);

        for (int target = 0; target <= T; target++) {
            long notTaken = prev[target];
            long taken = 0;

            if (arr[ind] <= target)
                taken = cur[target - arr[ind]];

            cur[target] = notTaken + taken;
        }

        prev = cur;
    }

    return prev[T];
}
