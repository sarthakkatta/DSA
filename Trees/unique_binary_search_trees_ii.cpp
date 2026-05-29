/*
Problem: LeetCode 95 – Unique Binary Search Trees II

Approach:
1. Use Recursion to generate all possible BSTs.
2. Function build(start, end):
   - Returns all unique BSTs that can be formed
     using values from start to end.
3. Base Case:
   - If start > end:
       → return {NULL}
4. Try every value as root:
   - rootVal from start to end
5. Generate:
   - All possible left subtrees
   - All possible right subtrees
6. Combine every left subtree with every right subtree:
   - Create new root node
   - Attach left and right children
   - Store tree in answer.
7. generateTrees(n):
   - Build BSTs using values 1 to n.

Key Idea:
- Every value can act as root, and all combinations
  of left and right subtrees must be explored.

Time Complexity: O(Cn)
  (Catalan Number growth)
Space Complexity: O(Cn)
*/

class Solution {
public:
    
    vector<TreeNode*> build(int start, int end) {
        if (start > end) {
            return {NULL};
        }
        vector<TreeNode*> ans;
        //Trying every value as root
        for (int rootVal = start; rootVal <= end; rootVal++) {
            //all possible left subtrees
            vector<TreeNode*> leftTrees = build(start, rootVal - 1);
            //all possible right subtrees
            vector<TreeNode*> rightTrees = build(rootVal + 1, end);
            // Combine every left subtree with every right subtree
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};
