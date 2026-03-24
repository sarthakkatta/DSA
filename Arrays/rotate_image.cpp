/*
Problem: LeetCode 48 – Rotate Image

Approach:
1. Rotate the matrix by 90 degrees clockwise.
2. First transpose the matrix (swap mat[i][j] with mat[j][i]).
3. Then reverse each row of the matrix.
4. This gives the required rotated matrix in-place.

Time Complexity: O(N^2)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        //transpose :
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        //reverse :
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};
