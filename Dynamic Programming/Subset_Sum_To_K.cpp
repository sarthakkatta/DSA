/*
Problem: Subset Sum Equal To K 

Approach:
1. For each element, we either take it or skip it.
2. Use DP where dp[i][target] tells whether sum = target is possible using first i elements.
3. Base case: sum 0 is always possible.
4. Memoization uses recursion + dp table.
5. Tabulation builds dp iteratively.
6. Space optimized version keeps only previous row.

Time Complexity: O(N * K)
Space Complexity:
Memoization → O(N * K)
Tabulation → O(N * K)
Space Optimized → O(K)
*/

                                    //MEMOIZATION :
#include <bits/stdc++.h>
using namespace std;

bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;              // Found a subset with sum=k
    if (ind == 0) return arr[0] == target;     // Only option: pick arr[0]

    if (dp[ind][target] != -1) return dp[ind][target];

    bool notTake = f(ind-1, target, arr, dp); // Don't pick arr[ind]
    bool take = false;
    if (arr[ind] <= target)
        take = f(ind-1, target-arr[ind], arr, dp); // Pick arr[ind]

    return dp[ind][target] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}
    
                                  // TABULATION:
#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Sum 0 can always be formed by taking nothing
    for (int i = 0; i < n; i++) dp[i][0] = true;

    // Base case for first element
    if (arr[0] <= k) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if (arr[i] <= target)
                take = dp[i-1][target-arr[i]];
            dp[i][target] = take || notTake;
        }
    }

    return dp[n-1][k];
}

                                //SPACE OPTIMISED:
#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false), curr(k+1, false);

    prev[0] = true; // Sum 0 is always possible

    if (arr[0] <= k) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        curr[0] = true; // Sum 0 always possible

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
