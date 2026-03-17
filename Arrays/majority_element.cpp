/*
Problem: LeetCode 169 – Majority Element

Approach:
1. Use Moore’s Voting Algorithm.
2. Maintain a candidate and a count.
3. If count becomes 0, update the candidate.
4. If the current element matches the candidate, increment count, otherwise decrement it.
5. The final candidate will be the majority element.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};
