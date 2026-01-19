/*
 Problem: Detect Cycle in a Directed Graph

 Approach (Kahn's Algorithm):
 - Calculate indegree of each node
 - Push all nodes with indegree 0 into queue
 - Remove nodes one by one and reduce indegree of neighbors
 - Count how many nodes are processed
 - If processed nodes < V → cycle exists

 Time Complexity: O(V + E)
 Space Complexity: O(V)
*/

class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (int neighbour : adj[i]) {
                indegree[neighbour]++;
            }
        }

        queue<int> q;
        // Push nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbour : adj[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // If all nodes are processed → no cycle
       if(cnt == V) return false; 
      return true;
    }
};
