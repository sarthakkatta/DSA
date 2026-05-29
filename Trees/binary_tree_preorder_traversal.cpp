/*
Problem: LeetCode 144 – Binary Tree Preorder Traversal

Approach:
1. Two approaches are shown:
   - Recursive Preorder Traversal
   - Iterative Preorder Traversal using Stack
2. Preorder Traversal order:
   - Root
   - Left Subtree
   - Right Subtree
3. Iterative Approach:
   - Push root node into stack.
   - Pop node and process it.
   - Push right child first.
   - Push left child second.
4. Since stack is LIFO:
   - Left child gets processed before right child.
5. Continue until stack becomes empty.

Key Idea:
- Stack simulates recursive preorder traversal.

Time Complexity: O(N)
Space Complexity: O(N)
*/

// class Solution {
// public:
//     void preorder(TreeNode* root, vector<int>& result){
//         if(root == NULL)return;
//         result.push_back(root->val);
//         preorder(root->left, result);
//         preorder(root->right, result);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         preorder(root, result);
//         return result;
//     }
// };


                             //BELOW ITERATIVE PREORDER TRAVERSAL H

class Solution{
    public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right != NULL){
                st.push(root->right);
            }
            if(root->left != NULL){
                st.push(root->left);
            }
        }
        return preorder;
    }
};
