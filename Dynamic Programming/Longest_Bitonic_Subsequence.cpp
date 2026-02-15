/*
Problem: Longest Bitonic Subsequence

Approach:
1. Compute LIS_dp[i] → LIS ending at index i.
2. Compute LDS_dp[i] → LDS starting from index i.
3. Bitonic length at i = LIS_dp[i] + LDS_dp[i] - 1.
4. Take maximum among all indices.
5. Return maximum bitonic length.

Time Complexity: O(N * N)
Space Complexity: O(N)
*/


class Solution {
public:

    int LongestBitonicSequence(vector<int>& arr) {
        int n = arr.size();
        vector<int> LIS_dp(n, 1);
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(arr[prev] < arr[i] &&
                   LIS_dp[i] < LIS_dp[prev] + 1) {
                    LIS_dp[i] = LIS_dp[prev] + 1;
                }
            }
        }

        vector<int> LDS_dp(n, 1);
        for(int i = n - 1; i >= 0; i--) {
            for(int prev = n - 1; prev > i; prev--) {
                if(arr[prev] < arr[i] &&
                   LDS_dp[i] < LDS_dp[prev] + 1) {
                    LDS_dp[i] = LDS_dp[prev] + 1;
                }
            }
            maxLen = max(maxLen,
                         LIS_dp[i] + LDS_dp[i] - 1);
        }
        return maxLen;
    }
};
