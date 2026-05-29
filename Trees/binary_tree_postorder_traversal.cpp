/*
Problem: LeetCode 145 – Binary Tree Postorder Traversal

Approach:
1. Two approaches are shown:
   - Recursive Postorder Traversal
   - Iterative Postorder Traversal using Two Stacks
2. Postorder Traversal order:
   - Left Subtree
   - Right Subtree
   - Root
3. Iterative Approach:
   - Push root into first stack (st1).
   - Pop node from st1 and push into st2.
   - Push left child into st1.
   - Push right child into st1.
4. After processing all nodes:
   - Pop elements from st2.
   - This produces Left → Right → Root order.
5. Store values in answer vector.

Key Idea:
- Two-stack method reverses modified preorder
  (Root → Right → Left) into postorder.

Time Complexity: O(N)
Space Complexity: O(N)
*/

// class Solution {
// public:
//     void postorder(TreeNode* root, vector<int>& result){
//         if(root == NULL)return;
//         postorder(root->left,result);
//         postorder(root->right,result);
//         result.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         postorder(root, result);
//         return result;
//     }
// };

                //Below IS THE ITERATIVE METHOD OF IMPLEMENTING POSTORDER USING TWO STACKS

class Solution{
    public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL){
                st1.push(root->left);
            }
            if(root->right != NULL){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};
