/*
Problem: LeetCode 104 – Maximum Depth of Binary Tree

Approach:
1. Use Recursion.
2. Base Case:
   - If root is NULL → depth = 0.
3. Recursively find:
   - Depth of left subtree.
   - Depth of right subtree.
4. Current depth:
   - 1 + max(left depth, right depth)
5. Return maximum depth of tree.

Key Idea:
- Depth of a node depends on the deeper subtree.

Time Complexity: O(N)
Space Complexity: O(H)
  (H = height of tree, recursion stack)
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};
