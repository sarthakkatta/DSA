/*
 Problem: Number of Ways to Arrive at Destination

 Approach:
 - Use Dijkstra’s Algorithm to find shortest distances
 - Along with distance, maintain number of ways to reach each node
 - If a shorter distance is found → update distance & copy ways
 - If same shortest distance is found → add number of ways
 - Return number of ways to reach destination modulo 1e9+7

 Time Complexity: O((V + E) log V)
 Space Complexity: O(V + E)
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Step 1: Build adjacency list (undirected weighted graph)
        vector<vector<pair<int, int>>> adj(n);
        for (auto &road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        // Min-heap: {distance, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        const int MOD = 1e9 + 7;
        // Step 2: Dijkstra with path counting
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            long long curDist = cur.first;
            int node = cur.second;
            // Skip outdated states
            if (curDist > dist[node])
                continue;
            for (auto &edge : adj[node]) {
                int nextNode = edge.first;
                int weight = edge.second;
                // Found a shorter path
                if (curDist + weight < dist[nextNode]) {
                    dist[nextNode] = curDist + weight;
                    ways[nextNode] = ways[node];
                    pq.push({dist[nextNode], nextNode});
                }
                // Found another shortest path
                else if (curDist + weight == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};
