/*
Problem: Unbounded Knapsack

Approach:
1. Each item can be taken unlimited number of times.
2. At every index, we have two choices:
   - Do not take the item → move to previous item.
   - Take the item → stay on same item and reduce capacity.
3. Use DP where dp[i][W] represents maximum value using items 0..i with capacity W.
4. Memoization uses recursion with caching.
5. Tabulation builds DP table bottom-up.
6. Space optimized version uses a single 1D array.

Time Complexity: O(N * W)
Space Complexity:
Memoization → O(N * W)
Tabulation → O(N * W)
Space Optimized → O(W)
*/

////////////////////////////////////////////////////////////
// MEMOIZATION
////////////////////////////////////////////////////////////

class Solution {
public:
    int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
        if (ind == 0) {
            return (W / wt[0]) * val[0];
        }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);

        int taken = INT_MIN;
        if (wt[ind] <= W)
            taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);

        return dp[ind][W] = max(notTaken, taken);
    }

    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return knapsackUtil(wt, val, n - 1, W, dp);
    }
};

////////////////////////////////////////////////////////////
// TABULATION
////////////////////////////////////////////////////////////

class Solution {
public:
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int i = wt[0]; i <= W; i++) {
            dp[0][i] = (i / wt[0]) * val[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int cap = 0; cap <= W; cap++) {
                int notTaken = dp[ind - 1][cap];

                int taken = INT_MIN;
                if (wt[ind] <= cap)
                    taken = val[ind] + dp[ind][cap - wt[ind]];

                dp[ind][cap] = max(notTaken, taken);
            }
        }

        return dp[n - 1][W];
    }
};

////////////////////////////////////////////////////////////
// SPACE OPTIMISED
////////////////////////////////////////////////////////////

class Solution {
public:
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        vector<int> cur(W + 1, 0);

        for (int i = wt[0]; i <= W; i++) {
            cur[i] = (i / wt[0]) * val[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int cap = 0; cap <= W; cap++) {
                int notTaken = cur[cap];

                int taken = INT_MIN;
                if (wt[ind] <= cap)
                    taken = val[ind] + cur[cap - wt[ind]];

                cur[cap] = max(notTaken, taken);
            }
        }

        return cur[W];
    }
};
