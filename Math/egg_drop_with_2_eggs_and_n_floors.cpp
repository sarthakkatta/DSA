/*
Problem: LeetCode 1884 – Egg Drop With 2 Eggs and N Floors

Approach:
1. Let moves represent the number of attempts.
2. With 2 eggs:
   - First drop intervals decrease by 1 each time.
3. After m moves, maximum floors that can be checked:
   - 1 + 2 + 3 + ... + m
   - = m * (m + 1) / 2
4. Keep increasing moves until:
   - Covered floors >= n
5. Return moves.

Key Idea:
- Find the smallest m such that:
      1 + 2 + 3 + ... + m ≥ n
- This guarantees the minimum worst-case number
  of moves with 2 eggs.

Time Complexity: O(√N)
Space Complexity: O(1)
*/

class Solution {
public:
    int twoEggDrop(int n) {
        int moves = 0;
        int covered = 0;

        while (covered < n) {
            moves++;
            covered += moves;
        }

        return moves;
    }
};
