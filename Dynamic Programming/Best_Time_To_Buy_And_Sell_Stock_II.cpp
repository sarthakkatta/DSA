/*
Problem: Best Time to Buy and Sell Stock II

Approach:
1. At each index we have two choices:
      buy (1)  → we can buy stock.
      not buy (0) → we can sell stock.
2. If buy:
      take max of (buy now OR skip).
3. If not buy:
      take max of (sell now OR skip).
4. dp[ind][buy] → maximum profit from index ind.
5. Base:
      when ind == n → profit = 0.
6. Space optimized using 4 variables.

Time Complexity: O(N)
Space Complexity:
Memoization → O(N * 2)
Tabulation → O(N * 2)
Space Optimized → O(1)
*/


// ======================= MEMOIZATION =======================

class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp) {

        if (ind == n) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        if (buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, prices, n, dp),
                         0 + f(ind + 1, 1, prices, n, dp));
        } else {
            profit = max(prices[ind] + f(ind + 1, 1, prices, n, dp),
                         0 + f(ind + 1, 0, prices, n, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n, dp);
    }
};



// ======================= TABULATION =======================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {

                if (buy) {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
                                       0 + dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 1][1],
                                       0 + dp[ind + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};



// ======================= SPACE OPTIMISED USING 2 ARRAYS =======================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {

                if (buy) {
                    curr[buy] = max(-prices[ind] + ahead[0],
                                    0 + ahead[1]);
                } else {
                    curr[buy] = max(prices[ind] + ahead[1],
                                    0 + ahead[0]);
                }
            }
            ahead = curr;
        }

        return ahead[1];
    }
};



// ======================= SPACE OPTIMISED USING 4 VARIABLES =======================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int aheadBuy = 0, aheadNotBuy = 0;
        int currBuy, currNotBuy;

        for (int ind = n - 1; ind >= 0; ind--) {

            currBuy = max(-prices[ind] + aheadNotBuy,
                          0 + aheadBuy);

            currNotBuy = max(prices[ind] + aheadBuy,
                             0 + aheadNotBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy;
    }
};
