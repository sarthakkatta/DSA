/*
Problem: Climbing Stairs II

Approach:
1. At each step i, you can jump:
   - 1 step → cost[i] + (1^2)
   - 2 steps → cost[i+1] + (2^2)
   - 3 steps → cost[i+2] + (3^2)
2. Goal: Reach exactly step n with minimum cost.
3. Multiple approaches shown:
   - Recursion → exponential (TLE)
   - Memoization → top-down DP
   - Tabulation → bottom-up DP
   - Space Optimization → only store next 3 states
4. In space optimized:
   - next1 → dp[i+1]
   - next2 → dp[i+2]
   - next3 → dp[i+3]
5. Iterate from back and compute minimum cost.

Time Complexity: O(N)
Space Complexity: O(1)
*/

                                    //RECURSION (IT WILL FAIL):
// class Solution {
// public:
//     int solve(int i, int n, vector<int> &costs){
//         if(i==n) return 0;
//         int ans = INT_MAX;
//         if(i + 1 <= n){
//             ans = min(ans, costs[i] + (1 * 1) + solve(i+1, n, costs));
//         }
//         if(i + 2 <= n){
//             ans = min(ans, costs[i + 1] + (2 * 2) + solve(i+2, n, costs));
//         }
//         if(i + 3 <= n){
//             ans = min(ans, costs[i + 2] + (3 * 3) + solve(i+3, n, costs));
//         }
//         return ans; 
//     }
//     int climbStairs(int n, vector<int>& costs) {
//         return solve(0,n, costs);
//     }
// };


                                    //MEMOIATION:
// class Solution {
// public:
//     int solve(int i, int n, vector<int> &costs, vector<int> &dp){
//         if(i==n) return 0;
//         if(dp[i] != -1)return dp[i];
//         int ans = INT_MAX;
//         if(i + 1 <= n){
//             ans = min(ans, costs[i] + (1 * 1) + solve(i+1, n, costs,dp));
//         }
//         if(i + 2 <= n){
//             ans = min(ans, costs[i + 1] + (2 * 2) + solve(i+2, n, costs,dp));
//         }
//         if(i + 3 <= n){
//             ans = min(ans, costs[i + 2] + (3 * 3) + solve(i+3, n, costs,dp));
//         }
//         dp[i] = ans;
//         return ans; 
//     }
//     int climbStairs(int n, vector<int>& costs) {
//         vector<int> dp(n +1 , -1);
//         return solve(0,n, costs, dp);
//     }
// };


                                              //TABULATION:
// class Solution {
// public:
//     int climbStairs(int n, vector<int>& costs) {
//         vector<int> dp(n + 1, INT_MAX);
//         dp[n] = 0; // base case
//         for(int i = n - 1; i >= 0; i--) {
//             if(i + 1 <= n) {
//                 dp[i] = min(dp[i], costs[i] + (1 * 1) + dp[i + 1]);
//             }
//             if(i + 2 <= n) {
//                 dp[i] = min(dp[i], costs[i + 1] + (2 * 2) + dp[i + 2]);
//             }
//             if(i + 3 <= n) {
//                 dp[i] = min(dp[i], costs[i + 2] + (3 * 3) + dp[i + 3]);
//             }
//         }
//         return dp[0];
//     }
// };



                                         //SPACE OPTIMISED:
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int next1 = 0; // dp[n]
        int next2 = 0; // dp[n+1] (invalid, treat as 0)
        int next3 = 0; // dp[n+2] (invalid, treat as 0)
        for(int i = n - 1; i >= 0; i--) {
            int ans = INT_MAX;
            if(i + 1 <= n) {
                ans = min(ans, costs[i] + 1 + next1);
            }

            if(i + 2 <= n) {
                ans = min(ans, costs[i + 1] + 4 + next2);
            }

            if(i + 3 <= n) {
                ans = min(ans, costs[i + 2] + 9 + next3);
            }
            next3 = next2;
            next2 = next1;
            next1 = ans;
        }
        return next1; // dp[0]
    }
};
