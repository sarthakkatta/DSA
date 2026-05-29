/*
Problem: LeetCode 96 – Unique Binary Search Trees

Approach:
1. Two approaches are shown:
   - Pure Recursion
   - Memoization (Optimized)
2. Let solve(n) represent:
   - Number of unique BSTs that can be formed
     using n nodes.
3. Base Case:
   - n <= 1 → only one possible BST.
4. Try every node as root:
   - Nodes on left = root - 1
   - Nodes on right = n - root
5. Number of BSTs for current root:
   - left_subtrees * right_subtrees
6. Sum results for all possible roots.
7. Memoize results to avoid recomputation.

Key Idea:
- This follows Catalan Number recurrence:
  BST(n) = Σ BST(left) × BST(right)

Time Complexity: O(N²)
Space Complexity: O(N)
*/

// class Solution {
// public:
//     int build(int start, int end){
//         if(start > end)
//             return 1;

//         int ans = 0;
//         for(int rootVal = start; rootVal <= end; rootVal++){
//             int leftCount = build(start, rootVal - 1);
//             int rightCount = build(rootVal + 1, end);
//             ans += leftCount * rightCount;
//         }
//         return ans;
//     }
//     int numTrees(int n) {
//         return build(1,n);
//     }
// };

class Solution {
public:
    int solve(int n, vector<int>& dp) {  
        if(n <= 1)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        int ans = 0;
        for(int root = 1; root <= n; root++) {    
            int left = solve(root - 1, dp);
            int right = solve(n - root, dp);

            ans += left * right;
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
