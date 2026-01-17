/*
 Problem: Number of Islands
 
 Approach:
 - Traverse the grid
 - When a '1' (land) is found, perform BFS to mark all connected land as visited
 - Each BFS call corresponds to one island

 Time Complexity: O(N * M)
 Space Complexity: O(N * M)   // queue in worst case
*/

class Solution {
private:
    void bfs(int startRow, int startCol, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({startRow, startCol});

        // Mark starting cell as visited
        grid[startRow][startCol] = '0';

        // Directions: down, up, right, left
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int newRow = row + dx[d];
                int newCol = col + dy[d];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == '1') {

                    q.push({newRow, newCol});
                    grid[newRow][newCol] = '0'; // mark visited
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    bfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};
