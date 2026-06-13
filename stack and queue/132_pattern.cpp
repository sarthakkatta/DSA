/*
Problem: LeetCode 456 – 132 Pattern

Approach:
1. Traverse the array from right to left.
2. Maintain:
   - Stack → possible candidates for "3" in 132 pattern.
   - third → candidate for "2" in 132 pattern.
3. For each element nums[i]:
   - If nums[i] < third:
       → Found a valid 132 pattern.
       → nums[i] = 1
       → third = 2
       → some larger value in stack = 3
4. While stack top is smaller than nums[i]:
   - Pop from stack.
   - Update third with popped value.
5. Push current element into stack.
6. If traversal ends without finding pattern:
   - Return false.

Key Idea:
- Scan from right to left.
- Stack keeps decreasing sequence of possible "3".
- `third` stores the best possible "2" value.

Pattern:
nums[i] < third < nums[j]

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int third = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {

            if (nums[i] < third)
                return true;

            while (!s.empty() && s.top() < nums[i]) {
                third = s.top();
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};
