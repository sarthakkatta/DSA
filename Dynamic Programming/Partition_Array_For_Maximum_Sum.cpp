/*
Problem: LeetCode 1043 – Partition Array for Maximum Sum

Approach:
1. Partition array into subarrays of size at most k.
2. For each partition → take max element * length.
3. dp[ind] → maximum sum from index ind to end.
4. Try all partitions from ind to ind+k-1.
5. Take maximum among all choices.

Time Complexity: O(N * K)
Space Complexity:
Memoization → O(N)
Tabulation → O(N)
*/


// ======================= MEMOIZATION =======================

class Solution {
public:

    int f(int ind,
          vector<int> &arr,
          int k,
          vector<int> &dp) {

        int n = arr.size();

        if (ind == n) return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int j = ind;
             j < min(ind + k, n);
             j++) {

            len++;

            maxi = max(maxi, arr[j]);

            int sum =
                len * maxi
                + f(j + 1, arr, k, dp);

            maxAns = max(maxAns, sum);
        }

        return dp[ind] = maxAns;
    }


    int maxSumAfterPartitioning(
        vector<int>& arr,
        int k) {

        int n = arr.size();

        vector<int> dp(n, -1);

        return f(0, arr, k, dp);
    }
};



// ======================= TABULATION =======================

class Solution{
public:

    int maxSumAfterPartitioning(
        vector<int>& num,
        int k) {

        int n = num.size();

        vector<int> dp(n + 1, 0);

        for (int ind = n - 1;
             ind >= 0;
             ind--) {

            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;

            for (int j = ind;
                 j < min(ind + k, n);
                 j++) {

                len++;

                maxi = max(maxi, num[j]);

                int sum =
                    len * maxi
                    + dp[j + 1];

                maxAns = max(maxAns, sum);
            }

            dp[ind] = maxAns;
        }

        return dp[0];
    }
};
