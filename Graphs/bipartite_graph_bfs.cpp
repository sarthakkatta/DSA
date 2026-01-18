/*
 Problem: Is Graph Bipartite?

 Approach:
 - Use Breadth First Search (BFS)
 - Color each node with one of two colors (0 or 1)
 - Adjacent nodes must have opposite colors
 - If a conflict is found, the graph is not bipartite

 Time Complexity: O(V + E)
 Space Complexity: O(V)
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);   // -1 → uncolored

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;   // start coloring

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbour : graph[node]) {
                        if (color[neighbour] == -1) {
                            color[neighbour] = 1 - color[node];
                            q.push(neighbour);
                        }
                        // Adjacent nodes with same color → not bipartite
                        else if (color[neighbour] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
