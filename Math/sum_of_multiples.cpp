/*
Problem: LeetCode 2652 – Sum Multiples

Approach:
1. Initialize:
   - sum = 0
2. Traverse all numbers from 1 to n.
3. For each number:
   - Check if it is divisible by
     3, 5, or 7.
4. If divisible:
   - Add it to the answer.
   - (Optionally store it in the vector.)
5. After processing all numbers,
   return the total sum.

Key Idea:
- Simply iterate through every number
  and include only those that are
  multiples of 3, 5, or 7.

Example:
Input:
n = 10

Multiples:
3, 5, 6, 7, 9, 10

Sum:
3 + 5 + 6 + 7 + 9 + 10 = 40

Output:
40

Time Complexity: O(N)
Space Complexity: O(N)
(The vector stores all valid multiples.
If the vector is removed, the space
complexity becomes O(1).)
*/

class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;

        vector<int> divs;

        for(int i = 1; i <= n; i++) {

            if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
                divs.push_back(i);
                sum += i;
            }
        }

        return sum;
    }
};
