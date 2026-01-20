/*
 Problem: Dijkstra Algorithm

 Approach:
 - Use adjacency list to represent weighted graph
 - Use min-heap (priority queue) to always pick node with minimum distance
 - Relax edges and update shortest distances
 - Works only for non-negative edge weights

 Time Complexity: O((V + E) log V)
 Space Complexity: O(V + E)
*/

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        // Step 1: Build adjacency list (undirected graph)
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // Step 2: Distance array
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        // Step 3: Min-heap {distance, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        pq.push({0, src});
        // Step 4: Dijkstra's Algorithm
        while (!pq.empty()) {
            int curDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            // Skip outdated entries
            if (curDist > dist[node])
                continue;

            for (auto &edge : adj[node]) {
                int adjNode = edge.first;
                int weight = edge.second;

                if (dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
