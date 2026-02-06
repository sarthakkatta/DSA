/*
Problem: LeetCode 322 – Coin Change

Approach:
1. For each amount, try all coins and pick the minimum count.
2. Use DP where dp[i][t] = minimum coins to form sum t using coins[0..i].
3. If coin value ≤ target, we can take it (stay on same index).
4. Otherwise skip current coin.
5. Memoization uses recursion + dp table.
6. Tabulation builds dp bottom-up.
7. Space optimized version keeps only previous row.

Time Complexity: O(N * Amount)
Space Complexity:
Memoization → O(N * Amount)
Tabulation → O(Amount)
Space Optimized → O(Amount)
*/

                                    //MEMOIZATION :
class Solution {
public:
    int f(int i, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) {
            if (target % coins[0] == 0) return target / coins[0];
            else return 1e9;
        }
        if (dp[i][target] != -1) return dp[i][target];

        int notTake = f(i - 1, target, coins, dp);
        int take = 1e9;
        if (coins[i] <= target)
            take = 1 + f(i, target - coins[i], coins, dp);
        
        return dp[i][target] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = f(n - 1, amount, coins, dp);
        return res >= 1e9 ? -1 : res;
    }
};


#include <bits/stdc++.h>
using namespace std;

                                   //TABULATION :
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};


                                                                   //SPACE OPTIMISED :
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minimumElements(vector<int>& arr, int T) {
        int n = arr.size();

        vector<int> prev(T + 1, 0);
        vector<int> cur(T + 1, 0);

        for (int i = 0; i <= T; i++) {
            if (i % arr[0] == 0)
                prev[i] = i / arr[0];
            else
                prev[i] = 1e9; 
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= T; target++) {

                int notTake = prev[target];

                int take = 1e9;
                if (arr[ind] <= target)
                    take = 1 + cur[target - arr[ind]];

                cur[target] = min(notTake, take);
            }

            prev = cur;
        }

        int ans = prev[T];
        if (ans >= 1e9) return -1;

        return ans;
    }
};
