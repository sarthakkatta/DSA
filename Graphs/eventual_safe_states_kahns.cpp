/*
 Problem: Find Eventual Safe States

 Approach:
 - Reverse the graph
 - Compute indegree of nodes in the reversed graph
 - Nodes with indegree 0 are terminal (safe)
 - Use Kahn’s Algorithm (BFS) to remove unsafe nodes
 - Remaining nodes are safe states

 Time Complexity: O(V + E)
 Space Complexity: O(V + E)
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        // Reverse graph
        vector<vector<int>> reverseAdj(V);
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int neighbour : graph[i]) {
                reverseAdj[neighbour].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        // Nodes with indegree 0 are terminal nodes
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;
        // Kahn’s Algorithm on reversed graph
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (int prevNode : reverseAdj[node]) {
                indegree[prevNode]--;
                if (indegree[prevNode] == 0) {
                    q.push(prevNode);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
