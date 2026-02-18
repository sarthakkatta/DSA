/*
Problem: LeetCode 312 – Burst Balloons


Approach:
1. Add 1 at beginning and end of array.
2. Try bursting each balloon as last in range i to j.
3. Coins = left coins + right coins + current burst coins.
4. dp[i][j] → maximum coins from range i to j.
5. Base:
      if i > j → coins = 0.

Time Complexity: O(N * N * N)
Space Complexity:
Memoization → O(N * N)
Tabulation → O(N * N)
*/


// ======================= MEMOIZATION =======================

class Solution {
public:

    int f(int i, int j,
          vector<int> &a,
          vector<vector<int>> &dp) {

        if (i > j) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;

        for (int ind = i;
             ind <= j;
             ind++) {

            int cost =
                a[i-1] * a[ind] * a[j+1]
                + f(i, ind-1, a, dp)
                + f(ind+1, j, a, dp);

            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }


    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.push_back(1);

        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(
            n+1,
            vector<int>(n+1, -1));

        return f(1, n, nums, dp);
    }
};



// ======================= TABULATION =======================

class Solution {
public:

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.push_back(1);

        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(
            n+2,
            vector<int>(n+2, 0));

        for (int i = n;
             i >= 1;
             i--) {

            for (int j = 1;
                 j <= n;
                 j++) {

                if (i > j) continue;

                int maxi = 0;

                for (int ind = i;
                     ind <= j;
                     ind++) {

                    int cost =
                        nums[i-1] * nums[ind] * nums[j+1]
                        + dp[i][ind-1]
                        + dp[ind+1][j];

                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};
