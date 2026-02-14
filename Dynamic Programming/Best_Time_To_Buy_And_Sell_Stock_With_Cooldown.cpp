/*
Problem: LeetCode 309 – Best Time to Buy and Sell Stock with Cooldown

Approach:
1. After selling stock, there is 1 day cooldown.
2. At each index we track:
      buy (0/1) → can buy or must sell.
3. If buy:
      buy now OR skip.
4. If not buy:
      sell now (move to ind+2 due to cooldown) OR skip.
5. dp[ind][buy] → maximum profit from index ind.
6. Base:
      if ind >= n → profit = 0.
7. Space optimized using 3 arrays.

Time Complexity: O(N)
Space Complexity:
Memoization → O(N * 2)
Tabulation → O(N * 2)
Space Optimized → O(1)
*/


// ======================= MEMOIZATION =======================

class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n,
          vector<vector<int>>& dp){

        if(ind >= n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy]; 

        if(buy==1){
            return dp[ind][buy] = max(
                -prices[ind] + f(ind + 1, 0, prices, n, dp),
                 0 + f(ind + 1, 1, prices, n, dp));
        }
        else{
            return dp[ind][buy] = max(
                prices[ind] + f(ind + 2, 1, prices, n, dp),
                 0 + f(ind + 1, 0, prices, n, dp));
        }
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

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int ind = n-1; ind >= 0; ind--){

            for(int buy = 0; buy <= 1; buy++){

                if(buy==1){
                    dp[ind][buy] = max(
                        -prices[ind] + dp[ind + 1][0],
                         0 + dp[ind + 1][1]);
                }
                else{
                    dp[ind][buy] = max(
                        prices[ind] + dp[ind + 2][1],
                         0 + dp[ind + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};



// ======================= REMOVING INNER FOR LOOP =======================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int ind = n-1; ind >= 0; ind--){

            dp[ind][1] = max(
                -prices[ind] + dp[ind + 1][0],
                 0 + dp[ind + 1][1]);

            dp[ind][0] = max(
                prices[ind] + dp[ind + 2][1],
                 0 + dp[ind + 1][0]);
        }

        return dp[0][1];
    }
};



// ======================= SPACE OPTIMISED =======================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> ahead1(2, 0); // dp[ind+1]
        vector<int> ahead2(2, 0); // dp[ind+2]
        vector<int> curr(2, 0);   // dp[ind]

        for (int ind = n - 1; ind >= 0; ind--) {

            curr[1] = max(
                -prices[ind] + ahead1[0],
                 0 + ahead1[1]);

            curr[0] = max(
                prices[ind] + ahead2[1],
                 0 + ahead1[0]);

            ahead2 = ahead1;
            ahead1 = curr;
        }

        return ahead1[1];
    }
};
