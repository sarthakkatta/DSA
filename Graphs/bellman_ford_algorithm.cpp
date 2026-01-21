/*
 Problem: Bellman Ford Algorithm

 Approach:
 - Initialize distance of source as 0 and others as infinity
 - Relax all edges (V - 1) times
 - Perform one extra relaxation to detect negative weight cycle
 - If a negative cycle exists, return {-1}

 Time Complexity: O(V * E)
 Space Complexity: O(V)
*/

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
        const int INF = 1e8;
        vector<int> dist(V, INF);
        dist[S] = 0;
        // Step 1: Relax edges (V - 1) times
        for (int i = 0; i < V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (dist[u] != INF && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Step 2: Check for negative weight cycle
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }
        return dist;
    }
};
