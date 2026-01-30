/*
Problem: LeetCode 460 – LFU Cache

Approach:
- Use two hash maps:

1) freqMap:
   frequency -> list of Nodes (DLL behavior using list)
   Each list maintains LRU order for same frequency.

2) keyNodeItMap:
   key -> iterator pointing to node inside freqMap list.

Extra variables:
- minFreq: minimum frequency currently present
- size: current number of elements
- cap: cache capacity

Operations:

GET(key):
- If key not found → return -1
- Else:
    → Remove node from current frequency list
    → Increase its frequency
    → Insert into new frequency list (front)
    → Update minFreq if needed

PUT(key,value):
- If key exists:
    → Update value
    → Call get(key) to increase frequency
- Else:
    → If cache full:
        remove LRU node from minFreq list
    → Insert new node with freq = 1
    → Update minFreq = 1

Time Complexity:
GET → O(1)
PUT → O(1)

Space Complexity: O(N)
*/

#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:

    struct Node {
        int key, val, freq;
        Node(int k, int v, int f = 1) : key(k), val(v), freq(f) {}
    };

    int cap, minFreq, size;

    // freq -> list of nodes
    unordered_map<int, list<Node>> freqMap;

    // key -> iterator of node in freqMap
    unordered_map<int, list<Node>::iterator> keyNodeItMap;

public:

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        size = 0;
    }

    int get(int key) {

        if (cap == 0 || keyNodeItMap.find(key) == keyNodeItMap.end())
            return -1;

        auto nodeIt = keyNodeItMap[key];
        int val = nodeIt->val;
        int freq = nodeIt->freq;

        // Remove node from current frequency list
        freqMap[freq].erase(nodeIt);

        if (freqMap[freq].empty()) {
            freqMap.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        // Add node to next frequency list
        freqMap[freq + 1].push_front(Node(key, val, freq + 1));
        keyNodeItMap[key] = freqMap[freq + 1].begin();

        return val;
    }

    void put(int key, int value) {

        if (cap == 0) return;

        // If key already exists
        if (keyNodeItMap.find(key) != keyNodeItMap.end()) {
            keyNodeItMap[key]->val = value;
            get(key);   // increase frequency
            return;
        }

        // Cache full → evict LFU + LRU
        if (size == cap) {

            Node nodeToRemove = freqMap[minFreq].back();
            keyNodeItMap.erase(nodeToRemove.key);
            freqMap[minFreq].pop_back();

            if (freqMap[minFreq].empty())
                freqMap.erase(minFreq);

            size--;
        }

        // Insert new node with freq = 1
        freqMap[1].push_front(Node(key, value));
        keyNodeItMap[key] = freqMap[1].begin();

        minFreq = 1;
        size++;
    }
};
