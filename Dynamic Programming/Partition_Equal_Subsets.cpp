/*
Problem: Partition Equal Subset Sum

Approach:
1. First calculate total sum of the array.
2. If total sum is odd, equal partition is impossible.
3. Otherwise target becomes totalSum / 2.
4. Reduce problem to checking if any subset gives sum = target.
5. Use DP where dp[i][t] tells whether sum t is possible using first i elements.
6. Memoization uses recursion + dp table.
7. Tabulation fills dp iteratively.
8. Space optimized version keeps only previous row.

Time Complexity: O(N * K)
Space Complexity:
Memoization → O(N * K)
Tabulation → O(N * K)
Space Optimized → O(K)
*/

                                                           //MEMOIATION:
#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to partition the array into two subsets with equal sum
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

bool canPartition(int n, vector<int>& arr) {
    int totSum = 0;

    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    if (totSum % 2 == 1)
        return false;
    else {
        int k = totSum / 2;

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return subsetSumUtil(n - 1, k, arr, dp);
    }
}


                                                                       //TABULATION:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(int n, vector<int>& arr) {
        
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (arr[0] <= targetSum) {
            dp[0][arr[0]] = true;
        }

        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= targetSum; target++) {
                bool notTaken = dp[index - 1][target];
                bool taken = false;
                if (arr[index] <= target) {
                    taken = dp[index - 1][target - arr[index]];
                }
                dp[index][target] = notTaken || taken;
            }
        }

        return dp[n - 1][targetSum];
    }
};


                                                                    //space optimised:
class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false), curr(k+1, false);

    prev[0] = true;

    if (arr[0] <= k) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        curr[0] = true;

        for (int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[i] <= target)
                take = prev[target-arr[i]];
            curr[target] = take || notTake;
        }

        prev = curr;
    }

    return prev[k];
}
 
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0; i < nums.size() ; i++) totalSum += nums[i];
        if(totalSum % 2) return false;
        int target = totalSum / 2;

        return subsetSumToK(nums.size(), target, nums);
    }
};
