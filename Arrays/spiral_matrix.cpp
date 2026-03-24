/*
Problem: LeetCode 54 – Spiral Matrix

Approach:
1. Use four pointers: top, bottom, left, right to define boundaries.
2. Traverse the matrix in four directions:
   - Left to Right
   - Top to Bottom
   - Right to Left
   - Bottom to Top
3. After each traversal, update the respective boundary.
4. Continue until all elements are visited.

Time Complexity: O(N * M)
Space Complexity: O(1) (excluding output)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        if (mat.empty() || mat[0].empty()) return ans;

        int n = mat.size();
        int m = mat[0].size();
        int top = 0, left = 0, right = m - 1, bottom = n - 1;

        while(top <= bottom && left <= right){
            for (int i = left; i <= right; i++) 
                ans.push_back(mat[top][i]);
            top++;

            for (int i = top; i <= bottom; i++) 
                ans.push_back(mat[i][right]);
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) 
                    ans.push_back(mat[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) 
                    ans.push_back(mat[i][left]);
                left++;
            }
        }
        return ans;
    }
};
