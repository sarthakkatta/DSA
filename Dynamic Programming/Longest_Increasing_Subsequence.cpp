/*
Problem: Longest Increasing Subsequence (LIS)

Approach:
1. Maintain a vector that stores smallest possible tail of LIS.
2. For each element:
      find position using lower_bound.
3. If element is greater than all → append.
4. Else replace element at position.
5. Size of vector = length of LIS.

Time Complexity:
Memoization → O(N * N)
Tabulation → O(N * N)
Space Optimized → O(N * N)
Binary Search → O(N * log N)

Space Complexity: O(N)
*/


// ======================= MEMOIZATION =======================

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int prevind, int arr[], int n, vector<vector<int>> &dp){

    if(ind == n) return 0;

    if(dp[ind][prevind + 1] != -1)
        return dp[ind][prevind+1];

    int len = f(ind+1, prevind, arr, n, dp);

    if(prevind == -1 || arr[ind] > arr[prevind]) {
        len = max(len, 1 + f(ind+1, ind, arr, n, dp));
    }

    return dp[ind][prevind+1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(0, -1, arr, n, dp);
}




// ======================= TABULATION =======================

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {

        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {

            int len = dp[ind + 1][prev_ind + 1];

            if (prev_ind == -1 || arr[ind] > arr[prev_ind]) {
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }

            dp[ind][prev_ind + 1] = len;
        }
    }

    return dp[0][0];
}




// ======================= SPACE OPTIMISED =======================

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {

    vector<int> next(n +1, 0), curr(n+1, 0);

    for (int ind = n - 1; ind >= 0; ind--) {

        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {

            int len = next[prev_ind + 1];

            if (prev_ind == -1 || arr[ind] > arr[prev_ind]) {
                len = max(len, 1 + next[ind + 1]);
            }

            curr[prev_ind + 1] = len;
        }

        next = curr;
    }

    return next[0];
}




// ======================= TABULATION ANOTHER STYLE =======================

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {

    vector<int> dp(n, 1);

    int maxi = 1;

    for (int i = 0; i < n; i++) {

        for (int prev = 0; prev < i; prev++) {

            if (arr[prev] < arr[i]) {

                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }

        maxi = max(maxi, dp[i]);
    }

    return maxi;
}




// ======================= BINARY SEARCH OPTIMISED =======================

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {

    vector<int> lis;

    for (int i = 0; i < n; i++) {

        int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

        if (pos == lis.size()) {
            lis.push_back(arr[i]);
        }
        else {
            lis[pos] = arr[i];
        }
    }

    return lis.size();
}
