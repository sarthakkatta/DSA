/*
Problem: LeetCode 1463 – Cherry Pickup II

Approach:
1. Two robots start from:
   - Robot1 → (0, 0)
   - Robot2 → (0, c-1)
2. At each row, both robots can move:
   - Left (-1), Stay (0), Right (+1)
3. Use 3D DP:
   - dp[i][j1][j2] → maximum cherries collected from row i when
     robot1 is at column j1 and robot2 at column j2.
4. Recurrence:
   - Try all 9 combinations of moves for both robots.
   - Add current cell(s):
       → If j1 == j2 → count once
       → Else → sum both cells
5. Base case:
   - Last row → return value(s) directly.
6. Memoize results to avoid recomputation.

Time Complexity: O(R * C * C * 9)
Space Complexity: O(R * C * C)
*/

// class Solution {
// public:
//     int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid) {
//         // Out of bounds
//         if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
//             return -1e8;

//         // Base case
//         if (i == r - 1) {
//             if (j1 == j2)
//                 return grid[i][j1];
//             else
//                 return grid[i][j1] + grid[i][j2];
//         }
//         int maxi = -1e8;

//         for (int dj1 = -1; dj1 <= 1; dj1++) {
//             for (int dj2 = -1; dj2 <= 1; dj2++) {
//                 int value;
//                 if (j1 == j2)
//                     value = grid[i][j1];
//                 else
//                     value = grid[i][j1] + grid[i][j2];

//                 value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
//                 maxi = max(maxi, value);
//             }
//         }
//         return maxi;
//     }
//     int cherryPickup(vector<vector<int>>& grid) {
//         int r = grid.size();
//         int c = grid[0].size();
//         return f(0, 0, c - 1, r, c, grid);
//     }
// };

                                       //MEMOIATION:
class Solution {
public:
    int f(int i, int j1, int j2, int r, int c,
          vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        // Out of bounds
        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
            return -1e8;

        // Base case
        if (i == r - 1) {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e8;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value;
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(
            r, vector<vector<int>>(c, vector<int>(c, -1))
        );
        return f(0, 0, c - 1, r, c, grid, dp);
    }
};
