/*
Problem: LeetCode 950 – Reveal Cards In Increasing Order

Approach:
1. Sort the deck in increasing order.
2. Create a deque containing all indices:
   - [0, 1, 2, ..., n-1]
3. Process cards in sorted order:
   - Take the front index from deque.
   - Place current card at that index.
4. Simulate reveal process:
   - After placing a card,
     move next front index to the back.
5. Continue until all cards are placed.
6. Return the constructed arrangement.

Key Idea:
- Instead of simulating card values,
  simulate positions where cards will be revealed.

Time Complexity: O(N log N)
  (sorting dominates)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end()); 

        int n = deck.size();
        vector<int> result(n);

        deque<int> indices;

        for (int i = 0; i < n; i++) {
            indices.push_back(i);
        }

        for (int card : deck) {
            int idx = indices.front();
            indices.pop_front();

            result[idx] = card;

            if (!indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }

        return result;
    }
};
