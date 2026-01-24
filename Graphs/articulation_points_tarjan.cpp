/*
 Problem: Articulation Points in a Graph

 Concept:
 - Use Tarjan's Algorithm to find articulation points (cut vertices)
 - A vertex is an articulation point if removing it increases
   the number of connected components in the graph

 Definitions:
 - tin[u]: time of insertion of node u in DFS
 - low[u]: lowest tin reachable from u (including back edges)

 Conditions:
 - Non-root node u is articulation point if:
     low[v] >= tin[u] for any child v
 - Root node is articulation point if it has more than one child

 Time Complexity: O(V + E)
 Space Complexity: O(V + E)
*/

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent,
             vector<int> &vis,
             vector<int> &tin,
             vector<int> &low,
             vector<int> &isArt,
             vector<int> adj[]) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int children = 0;

        for (auto neigh : adj[node]) {
            if (neigh == parent) continue;

            if (!vis[neigh]) {
                dfs(neigh, node, vis, tin, low, isArt, adj);
                low[node] = min(low[node], low[neigh]);
                // Articulation point condition (non-root)
                if (low[neigh] >= tin[node] && parent != -1) {
                    isArt[node] = 1;
                }
                children++;
            } else {
                // Back edge
                low[node] = min(low[node], tin[neigh]);
            }
        }
        // Root node articulation condition
        if (parent == -1 && children > 1) {
            isArt[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> vis(n, 0), isArt(n, 0);
        vector<int> tin(n, -1), low(n, -1);
        // Graph may be disconnected
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, isArt, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (isArt[i]) ans.push_back(i);
        }
        return ans.empty() ? vector<int>{-1} : ans;
    }
};
