/*
Problem: LeetCode 124 – Binary Tree Maximum Path Sum

Approach:
1. Use DFS to compute maximum path contribution
   from each node.
2. For every node:
   - Compute maximum contribution from left subtree.
   - Compute maximum contribution from right subtree.
3. Ignore negative contributions:
   - max(0, left path)
   - max(0, right path)
4. Path passing through current node:
   - left contribution + right contribution + root->val
5. Update global maximum path sum.
6. Return contribution to parent:
   - max(left contribution, right contribution) + root->val
7. Final answer is stored in maxi.

Key Idea:
- A valid maximum path may start and end at any node.
- At each node, check whether it forms the highest path.

Time Complexity: O(N)
Space Complexity: O(H)
  (H = height of tree due to recursion stack)
*/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; 
        findMaxPathSum(root, maxi);
        return maxi; 
    }
    int findMaxPathSum(TreeNode* root, int &maxi) {
        if (root == nullptr) {
            return 0;
        }
        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);
        return max(leftMaxPath, rightMaxPath) + root->val;
    }
};
