/*
Problem: LeetCode 102 – Binary Tree Level Order Traversal

Approach:
1. Use Breadth First Search (BFS).
2. Initialize queue with root node.
3. While queue is not empty:
   - Get current level size.
   - Process all nodes of that level.
4. For each node:
   - Add its value to current level vector.
   - Push left child into queue (if exists).
   - Push right child into queue (if exists).
5. Store current level in answer.
6. Return final level-order traversal.

Key Idea:
- Queue processes nodes level by level.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root ==  NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
          int size = q.size();
          vector<int> level;
          for(int i = 0;i < size ; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL)q.push(node->left);
            if(node->right != NULL)q.push(node->right);
            level.push_back(node->val);
          }
          ans.push_back(level);
        }
        return ans;
    }
};
