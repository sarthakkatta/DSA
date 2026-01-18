/*
 Problem: 01 Matrix (Distance to Nearest Zero)

 Approach:
 - Use Multi-source BFS
 - Push all cells with value 0 into the queue initially
 - Perform BFS to compute the shortest distance to a zero for each cell
 - Each BFS layer increases distance by 1

 Time Complexity: O(N * M)
 Space Complexity: O(N * M)
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[row][col] = steps;

            for (int i = 0; i < 4; i++) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    !visited[newRow][newCol]) {

                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, steps + 1});
                }
            }
        }

        return dist;
    }
};
