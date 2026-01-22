/*
 Problem: Find the City With the Smallest Number of Neighbors at a Threshold Distance

 Approach:
 - Use Floyd–Warshall to compute all-pairs shortest paths
 - For each city, count how many cities are reachable within distanceThreshold
 - Choose the city with the minimum count
 - If there is a tie, return the city with the greatest index

 Time Complexity: O(N^3)
 Space Complexity: O(N^2)
*/

class Solution {
public:
    int findTheCity(int n,
                    vector<vector<int>>& edges,
                    int distanceThreshold) {

        const int INF = INT_MAX;
        // Step 1: Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        // Step 2: Floyd–Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );
                    }
                }
            }
        }
        // Step 3: Find the city with minimum reachable neighbors
        int minCount = n;
        int cityNumber = -1;
        for (int city = 0; city < n; city++) {
            int reachable = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (dist[city][adjCity] <= distanceThreshold)
                    reachable++;
            }
            // Tie-breaking: choose city with greater index
            if (reachable <= minCount) {
                minCount = reachable;
                cityNumber = city;
            }
        }
        return cityNumber;
    }
};
