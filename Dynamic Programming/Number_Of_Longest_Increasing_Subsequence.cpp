/*
Problem: LeetCode 673 – Number of Longest Increasing Subsequence

Approach:
1. dp[i] → length of LIS ending at index i.
2. ct[i] → number of LIS ending at index i.
3. If longer LIS found → update dp[i] and copy count.
4. If same length LIS found → add count.
5. Find maximum LIS length and sum counts of those indices.

Time Complexity: O(N * N)
Space Complexity: O(N)
*/


class Solution {
public:

    int findNumberOfLIS(vector<int>& arr) {

        int n = arr.size();

        vector<int> dp(n, 1);

        vector<int> ct(n, 1);

        int maxi = 1;


        for (int i = 0; i < n; i++) {

            for (int prev_index = 0;
                 prev_index < i;
                 prev_index++) {

                if (arr[prev_index] < arr[i] &&
                    dp[prev_index] + 1 > dp[i]) {

                    dp[i] = dp[prev_index] + 1;

                    ct[i] = ct[prev_index];
                }

                else if (arr[prev_index] < arr[i] &&
                         dp[prev_index] + 1 == dp[i]) {

                    ct[i] = ct[i] + ct[prev_index];
                }
            }

            maxi = max(maxi, dp[i]);
        }


        int numberOfLIS = 0;

        for (int i = 0; i < n; i++) {

            if (dp[i] == maxi) {

                numberOfLIS += ct[i];
            }
        }

        return numberOfLIS;
    }
};
