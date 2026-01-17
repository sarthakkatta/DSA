/*
 Problem: Number of Provinces

 Approach:
 - Convert the given adjacency matrix into an adjacency list
 - Use Depth First Search (DFS) to find connected components
 - Each DFS call represents one province

 Time Complexity: O(V^2)
 Space Complexity: O(V + E)
*/

class Solution {
private:
    // DFS to mark all connected nodes
    void dfs(int node, vector<int> adj[], vector<int> &visited) {
        visited[node] = 1;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        // Convert adjacency matrix to adjacency list
        vector<int> adj[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> visited(V, 0);
        int provinces = 0;

        // Count connected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, adj, visited);
            }
        }

        return provinces;
    }
};
