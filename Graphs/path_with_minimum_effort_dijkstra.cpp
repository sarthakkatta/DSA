/*
 Problem: Path With Minimum Effort

 Approach:
 - Use Dijkstra's Algorithm on a grid
 - The "distance" here is the maximum absolute height difference along the path
 - For each cell, try all 4 directions
 - Relax the path by minimizing the maximum effort so far
 - First time reaching destination gives the minimum effort

 Time Complexity: O((N * M) log (N * M))
 Space Complexity: O(N * M)
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // Min-heap: {effort, {row, col}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        // Directions: up, right, down, left
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int effort = cur.first;
            int row = cur.second.first;
            int col = cur.second.second;
            // Destination reached with minimum effort
            if (row == n - 1 && col == m - 1)
                return effort;
            // Skip outdated entries
            if (effort > dist[row][col])
                continue;
            for (int i = 0; i < 4; i++) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m) {
                    int newEffort = max(
                        abs(heights[row][col] - heights[newRow][newCol]),
                        effort
                    );
                    if (newEffort < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        return 0; // Should never reach here
    }
};
