/*
Problem: LeetCode 70 – Climbing Stairs

Approach:
- This is a Fibonacci-style DP problem.
- From any step, you can climb either 1 or 2 stairs.
- So:
      ways(n) = ways(n-1) + ways(n-2)

Instead of using full DP array, we optimize space:
- a → ways to reach (i-2)
- b → ways to reach (i-1)
- temp → current ways

Iteratively compute till n.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int a = 1;   // ways to reach step 1
        int b = 2;   // ways to reach step 2

        for(int i = 3; i <= n; i++) {
            int temp = a + b;  // current ways
            a = b;
            b = temp;
        }
        return b;
    }
};
