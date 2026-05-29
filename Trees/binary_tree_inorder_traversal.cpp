/*
Problem: LeetCode 94 – Binary Tree Inorder Traversal

Approach:
1. Two approaches are shown:
   - Recursive Inorder Traversal
   - Iterative Inorder Traversal using Stack
2. Inorder Traversal order:
   - Left Subtree
   - Root Node
   - Right Subtree
3. Iterative Approach:
   - Keep moving left and push nodes into stack.
   - When NULL is reached:
       → pop node from stack
       → process node
       → move to right subtree
4. Continue until:
   - Current node is NULL
   - Stack becomes empty

Key Idea:
- Stack simulates recursion and stores nodes
  whose left subtree is being processed.

Time Complexity: O(N)
Space Complexity: O(N)
*/

// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& result){
//         if(root == NULL)return;
//         inorder(root->left,result);
//         result.push_back(root->val);
//         inorder(root->right,result);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         inorder(root, result);
//         return result;
//     }
// };


                               //INORDER TRAVERSAL:
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};
