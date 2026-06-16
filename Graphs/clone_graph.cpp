/*
Problem: LeetCode 133 – Clone Graph

Approach:
1. Use DFS + HashMap.
2. Maintain:
   - mp[original node] = cloned node
3. Base Cases:
   - If node is NULL → return nullptr.
   - If node is already cloned:
       → return existing clone from map.
4. Create clone of current node.
5. Store mapping:
   - original node → cloned node
6. Traverse all neighbors:
   - Recursively clone each neighbor.
   - Add cloned neighbors to current clone.
7. Return cloned node.

Key Idea:
- HashMap prevents cloning the same node multiple times
  and handles cycles in the graph.

Time Complexity: O(V + E)
Space Complexity: O(V)
  (HashMap + Recursion Stack)
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (mp.count(node))
            return mp[node];

        Node* clone = new Node(node->val);

        mp[node] = clone;

        for (Node* nei : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(nei));
        }

        return clone;
    }
};
