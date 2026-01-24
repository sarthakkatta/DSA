/*
 Problem: Swim in Rising Water

 Concept:
 - This is a variation of Dijkstra's algorithm
 - Instead of minimizing total distance, we minimize the maximum
   height encountered on the path (minimax problem)

 Approach:
 - Use a min-heap (priority queue)
 - State: {currentTime, {row, col}}
 - currentTime = max(height so far on the path)
 - Always expand the cell with the minimum currentTime

 Time Complexity: O(N^2 log N)
 Space Complexity: O(N^2)
*/

class Solution {
public:
    using Node = pair<int, pair<int, int>>; // {time, {row, col}}
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        // Start from (0,0)
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int time = cur.first;
            int r = cur.second.first;
            int c = cur.second.second;
            // Destination reached
            if (r == n - 1 && c == n - 1)
                return time;
            // Skip outdated entry
            if (time > dist[r][c]) continue;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int nextTime = max(time, grid[nr][nc]);
                    if (nextTime < dist[nr][nc]) {
                        dist[nr][nc] = nextTime;
                        pq.push({nextTime, {nr, nc}});
                    }
                }
            }
        }
        return -1; // Guaranteed not to happen
    }
};
