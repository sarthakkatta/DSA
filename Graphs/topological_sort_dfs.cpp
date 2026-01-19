/*
 Problem: Topological Sort

 Approach:
 - Use Depth First Search (DFS)
 - Perform DFS and push nodes to stack after visiting all neighbors
 - Reverse of finishing times gives topological order
 - Works only for Directed Acyclic Graphs (DAG)

 Time Complexity: O(V + E)
 Space Complexity: O(V)
*/

class Solution {
private:
    void dfs(int node, vector<int>& visited,
             stack<int>& st, vector<int> adj[]) {
        visited[node] = 1;
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, visited, st, adj);
            }
        }
        // Push node after all its dependencies are processed
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, st, adj);
            }
        }

        vector<int> topoOrder;
        while (!st.empty()) {
            topoOrder.push_back(st.top());
            st.pop();
        }

        return topoOrder;
    }
};
