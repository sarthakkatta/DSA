/*
Problem: LeetCode 543 – Diameter of Binary Tree

Approach:
1. Use DFS to calculate height of every node.
2. For each node:
   - Find left subtree height (lh).
   - Find right subtree height (rh).
3. Diameter passing through current node:
   - lh + rh
4. Update global diameter:
   - diameter = max(diameter, lh + rh)
5. Return height of current node:
   - 1 + max(lh, rh)
6. Final diameter stores the maximum number
   of edges between any two nodes.

Key Idea:
- The longest path through a node is the sum
  of heights of its left and right subtrees.

Time Complexity: O(N)
Space Complexity: O(H)
  (H = height of tree due to recursion stack)
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    private:
    int height(TreeNode* node , int& diameter){
        if(!node) return 0;

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);

        return 1 + max(lh , rh);
    }
};
