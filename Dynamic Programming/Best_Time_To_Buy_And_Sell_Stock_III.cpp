/*
Problem: LeetCode 123 – Best Time to Buy and Sell Stock III

Approach:
1. We can complete at most 2 transactions.
2. At each index we track:
      buy (0/1) and remaining cap (transactions left).
3. If buy:
      choose buy now OR skip.
4. If not buy:
      choose sell now (reduce cap) OR skip.
5. dp[i][buy][cap] → maximum profit from index i.
6. Base:
      if i == n OR cap == 0 → profit = 0.
7. Space optimized using 2 arrays (2 × 3).

Time Complexity: O(N * 2 * 2)
Space Complexity:
Memoization → O(N * 2 * 3)
Tabulation → O(N * 2 * 3)
Space Optimized → O(2 * 3)
*/


// ======================= MEMOIZATION =======================

class Solution {
public:
    int f(int i, int buy, int cap, vector<int>& prices, int n,
          vector<vector<vector<int>>>& dp) {

        if (i == n || cap == 0) return 0;

        if (dp[i][buy][cap] != -1) return dp[i][buy][cap];

        if (buy == 1) {
            dp[i][buy][cap] = max(
                -prices[i] + f(i + 1, 0, cap, prices, n, dp),
                 0 + f(i + 1, 1, cap, prices, n, dp));
        } else {
            dp[i][buy][cap] = max(
                prices[i] + f(i + 1, 1, cap - 1, prices, n, dp),
                 0 + f(i + 1, 0, cap, prices, n, dp));
        }

        return dp[i][buy][cap];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, n, dp);
    }
};



// ======================= MEMOIZATION (Transaction Number Approach) =======================

class Solution {
public:
    int f(int ind, int trans, vector<int>& prices, int n,
          vector<vector<int>>& dp) {

        if (ind == n || trans == 4) return 0;

        if (dp[ind][trans] != -1) return dp[ind][trans];

        if (trans % 2 == 0) {
            return dp[ind][trans] = max(
                -prices[ind] + f(ind + 1, trans + 1, prices, n, dp),
                 0 + f(ind + 1, trans, prices, n, dp));
        } else {
            return dp[ind][trans] = max(
                prices[ind] + f(ind + 1, trans + 1, prices, n, dp),
                 0 + f(ind + 1, trans, prices, n, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -1));
        return f(0, 0, prices, n, dp);
    }
};



// ======================= TABULATION =======================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {

                    if (buy == 1) {
                        dp[i][buy][cap] = max(
                            -prices[i] + dp[i + 1][0][cap],
                             0 + dp[i + 1][1][cap]);
                    } else {
                        dp[i][buy][cap] = max(
                            prices[i] + dp[i + 1][1][cap - 1],
                             0 + dp[i + 1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};



// ======================= SPACE OPTIMISED USING 6 SIZE ARRAY =======================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {

                    if (buy == 1) {
                        cur[buy][cap] = max(
                            -prices[i] + after[0][cap],
                             0 + after[1][cap]);
                    } else {
                        cur[buy][cap] = max(
                            prices[i] + after[1][cap - 1],
                             0 + after[0][cap]);
                    }
                }
            }
            after = cur;
        }

        return after[1][2];
    }
};
