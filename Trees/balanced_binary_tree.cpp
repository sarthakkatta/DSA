/*
Problem: LeetCode 110 – Balanced Binary Tree

Approach:
1. Use Postorder DFS traversal.
2. Helper function dfsHeight():
   - Returns height of subtree if balanced.
   - Returns -1 if subtree is unbalanced.
3. Base Case:
   - NULL node → height = 0.
4. Recursively calculate:
   - left subtree height
   - right subtree height
5. Early termination:
   - If left subtree is unbalanced → return -1.
   - If right subtree is unbalanced → return -1.
6. Check balance condition:
   - abs(leftHeight - rightHeight) <= 1
7. If violated:
   - Return -1.
8. Otherwise:
   - Return subtree height.
9. Tree is balanced if final result is not -1.

Key Idea:
- Height calculation and balance checking
  are done together in a single DFS traversal.

Time Complexity: O(N)
Space Complexity: O(H)
  (H = height of tree due to recursion stack)
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight , rightHeight) + 1; 
    }
};
