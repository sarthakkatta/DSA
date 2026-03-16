/*
Problem: LeetCode 189 – Rotate Array

Approach:
1. Use the Reversal Algorithm to rotate the array.
2. First reverse the entire array.
3. Then reverse the first k elements.
4. Finally reverse the remaining n-k elements.
5. This effectively rotates the array to the right by k steps.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return nums;
        }
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        return nums;
    }
};
