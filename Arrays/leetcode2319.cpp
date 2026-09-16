/*
Problem:
---------
LeetCode 2319 - Check if Matrix Is X-Matrix

Approach:
---------
1. Traverse every cell of the n × n matrix using two nested loops.

2. For every cell `(i, j)`, check whether it belongs to either of the
   two diagonals:
   
       Main diagonal:
           i == j
       
       Anti-diagonal:
           i + j == n - 1

3. If the cell belongs to either diagonal:
   - Its value must be non-zero.
   - If `grid[i][j] == 0`, the matrix is not an X-Matrix.
   - Return false.

4. If the cell does NOT belong to either diagonal:
   - Its value must be zero.
   - If `grid[i][j] != 0`, the matrix is not an X-Matrix.
   - Return false.

5. If every cell satisfies its required condition:
   - All diagonal elements are non-zero.
   - All non-diagonal elements are zero.
   - Therefore, the matrix is an X-Matrix.
   - Return true.

Key Idea:
---------
An X-Matrix has two important rules:

    1. Both diagonals must contain non-zero values.
    2. Every cell outside both diagonals must contain 0.

The two diagonal conditions are:

    i == j

for the main diagonal, and:

    i + j == n - 1

for the anti-diagonal.

So for every cell, we simply determine whether it belongs to the X
or not and check its value accordingly.

Example:
--------
grid =
    5  0  0  0  7
    0  4  0  8  0
    0  0  9  0  0
    0  6  0  2  0
    3  0  0  0  1

All cells on both diagonals are non-zero, and every other cell is zero.

Therefore:

    Answer = true

Example 2:
----------
grid =
    5  0  0
    0  0  8
    3  0  1

The center cell `(1,1)` belongs to both diagonals, but its value is 0.

Therefore, the X-Matrix condition is violated.

Answer = false.

Time Complexity:
----------------
O(n²)

Every cell of the matrix is visited exactly once.

Space Complexity:
-----------------
O(1)

Only a few variables are used and no extra data structure is created.
*/

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j || (i + j) == n - 1){
                    if(grid[i][j] == 0) return false;
                }else if(grid[i][j] != 0) return false;
            }
        }
        return true;
    }
};
