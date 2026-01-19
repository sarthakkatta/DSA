/*
 Problem: Shortest Path in Undirected Graph (Unit Weight)

 Approach:
 - Since all edges have equal weight (1), use BFS
 - Build adjacency list from edge list
 - Initialize distance array with -1
 - Start BFS from source node and update distances

 Time Complexity: O(V + E)
 Space Complexity: O(V + E)
*/

class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(V, -1);
      
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbour : adj[node]) {
                if (dist[neighbour] == -1) {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }
        return dist;
    }
};
