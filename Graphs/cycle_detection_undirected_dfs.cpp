/*
 Problem: Detect Cycle in an Undirected Graph

 Approach:
 - Use Depth First Search (DFS)
 - Track parent of each node during traversal
 - If a visited neighbor is not the parent, a cycle exists

 Time Complexity: O(V + E)
 Space Complexity: O(V)   // recursion stack + visited array
*/

class Solution {
private:
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (dfs(neighbour, node, adj, visited))
                    return true;
            }
            // If visited neighbour is not parent → cycle
            else if (neighbour != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
