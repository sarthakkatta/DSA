/*
Problem: LeetCode 1486 – XOR Operation in an Array

Approach:
1. Initialize:
   - ans = 0
2. Generate the array elements one by one.
3. The ith element is:
      start + 2 × i
4. Instead of storing the array:
   - XOR each generated value directly
     with the answer.
5. After processing all n elements,
   return the final XOR value.

Key Idea:
- The array does not need to be created.
- Generate each element on the fly and
  continuously update the XOR result.

Example:
Input:
n = 5
start = 0

Generated Array:
0, 2, 4, 6, 8

XOR:
0 ^ 2 ^ 4 ^ 6 ^ 8 = 8

Output:
8

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;

        while (n--) {
            ans ^= start;
            start += 2;
        }

        return ans;
    }
};
