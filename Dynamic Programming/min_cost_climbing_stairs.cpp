/*
Problem: LeetCode 746 – Min Cost Climbing Stairs

Approach:
1. At each index i, you can move:
   - 1 step → i + 1
   - 2 steps → i + 2
2. Goal: Reach the top (beyond last index) with minimum cost.
3. Two approaches shown:
   - Memoization → top-down recursion with DP
   - Tabulation → bottom-up DP
4. In tabulation:
   - dp[i] represents minimum cost to reach the top from index i.
   - Compute from back:
       dp[i] = cost[i] + min(dp[i+1], dp[i+2])
5. Final answer:
   - Start either from index 0 or 1 → take minimum.

Time Complexity: O(N)
Space Complexity: O(N)
*/

                                          //MEMOIATION:
// class Solution {
// public:
//     int solve(int i, int n, vector<int> &costs,vector<int> &dp){
//         if(i >= n) return 0;
//         if(dp[i] != -1) return dp[i];
//         int oneStep = solve(i + 1, n,costs,dp);
//         int twoStep = solve(i + 2,n, costs,dp);

//         int minCost = min(oneStep, twoStep);

//         int totalCost = costs[i] + minCost;
//         dp[i] = totalCost;
//         return totalCost;
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n + 1, -1);
//         return min(solve(0, n, cost,dp),solve(1, n, cost,dp));
//     }
// };

                                   //TABULATION:
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 2, 0); 
        for(int i = n - 1; i >= 0; i--) {

            int oneStep = dp[i + 1];  
            int twoStep = dp[i + 2];  

            int minCost = min(oneStep, twoStep);

            dp[i] = cost[i] + minCost;
        }

        return min(dp[0], dp[1]);
    }
};
