/*
Problem: LeetCode 368 – Largest Divisible Subset

Approach:
1. Sort the array.
2. Use DP to store length of largest divisible subset ending at each index.
3. If nums[i] % nums[j] == 0 → update dp[i] and store parent.
4. Track index of maximum length subset.
5. Reconstruct subset using parent array.

Time Complexity: O(N * N)
Space Complexity: O(N)
*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), parent(n, -1);

        int maxLen = 1, maxIndex = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (nums[i] % nums[j] == 0 &&
                    dp[j] + 1 > dp[i]) {

                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }


        vector<int> result;

        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
