/*
 Problem: Minimum Multiplications to Reach End

 Approach:
 - Treat each number (0 to 99999) as a node
 - From a node x, you can go to (x * arr[i]) % 100000
 - Use BFS since each operation has equal cost (1 step)
 - Maintain distance array to avoid revisiting states
 - Stop BFS as soon as the target is reached

 Time Complexity: O(100000 * N)
 Space Complexity: O(100000)
*/

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) 
        const int MOD = 100000;
        vector<int> dist(MOD, 1e9);
        dist[start] = 0;
        // Queue stores {currentNumber, steps}
        queue<pair<int, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int node = cur.first;
            int steps = cur.second;
            for (int multiplier : arr) {
                int next = (node * multiplier) % MOD;
                if (steps + 1 < dist[next]) {
                    dist[next] = steps + 1;
                    // If destination reached
                    if (next == end)
                        return steps + 1;
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;  // Destination not reachable
    }
};
