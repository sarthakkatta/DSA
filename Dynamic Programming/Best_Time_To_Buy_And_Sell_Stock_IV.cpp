/*
Problem: LeetCode 188 – Best Time to Buy and Sell Stock IV

Approach:
1. We can complete at most k transactions.
2. At each index we track:
      buy (0/1) and remaining cap.
3. If buy:
      choose buy now OR skip.
4. If not buy:
      choose sell now (reduce cap) OR skip.
5. dp[i][buy][cap] → maximum profit from index i.
6. Base:
      if i == n OR cap == 0 → profit = 0.
7. Space optimized using 2 × (k+1) array.

Time Complexity: O(N * 2 * K)
Space Complexity:
Memoization → O(N * 2 * K)
Tabulation → O(N * 2 * K)
Space Optimized → O(2 * K)
*/


// ======================= MEMOIZATION =======================

class Solution {
public:
    int f(int i, int buy, int cap, vector<int>& prices, int n,
          vector<vector<vector<int>>>& dp) {

        if (i == n || cap == 0) return 0;

        if (dp[i][buy][cap] != -1) return dp[i][buy][cap];

        if (buy) {
            return dp[i][buy][cap] = max(
                -prices[i] + f(i + 1, 0, cap, prices, n, dp),
                 0 + f(i + 1, 1, cap, prices, n, dp)
            );
        } else {
            return dp[i][buy][cap] = max(
                prices[i] + f(i + 1, 1, cap - 1, prices, n, dp),
                 0 + f(i + 1, 0, cap, prices, n, dp)
            );
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, k, prices, n, dp);
    }
};



// ======================= MEMOIZATION (Using Transaction Number) =======================

class Solution {
public:
    int f(int ind, int trans, int k, vector<int>& prices, int n,
          vector<vector<int>>& dp) {

        if (ind == n || trans == 2 * k) return 0;

        if (dp[ind][trans] != -1) return dp[ind][trans];

        if (trans % 2 == 0) {
            return dp[ind][trans] = max(
                -prices[ind] + f(ind + 1, trans + 1, k, prices, n, dp),
                 0 + f(ind + 1, trans, k, prices, n, dp)
            );
        } else {
            return dp[ind][trans] = max(
                prices[ind] + f(ind + 1, trans + 1, k, prices, n, dp),
                 0 + f(ind + 1, trans, k, prices, n, dp)
            );
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, -1));
        return f(0, 0, k, prices, n, dp);
    }
};



// ======================= TABULATION =======================

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {

                    if (buy) {
                        dp[i][buy][cap] = max(
                            -prices[i] + dp[i + 1][0][cap],
                             0 + dp[i + 1][1][cap]
                        );
                    } else {
                        dp[i][buy][cap] = max(
                            prices[i] + dp[i + 1][1][cap - 1],
                             0 + dp[i + 1][0][cap]
                        );
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};



// ======================= SPACE OPTIMISED =======================

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> after(2, vector<int>(k + 1, 0)),
                            cur(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {

                    if (buy) {
                        cur[buy][cap] = max(
                            -prices[i] + after[0][cap],
                             0 + after[1][cap]
                        );
                    } else {
                        cur[buy][cap] = max(
                            pri
