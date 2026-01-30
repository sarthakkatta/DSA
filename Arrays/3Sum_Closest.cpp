/*
Problem: LeetCode 16 – 3Sum Closest

Approach:
- Sort the array.
- Fix one element (i) and use two pointers (left, right) for remaining two.
- For every triplet:
    → Calculate sum.
    → Update result if this sum is closer to target.
- Move pointers based on comparison with target:
    → sum < target → left++
    → sum > target → right--
- If sum == target, return immediately.

Time Complexity: O(N^2)
Space Complexity: O(1) (excluding sort)

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // Initial result using first three elements
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // Update closest sum
                if (abs(target - sum) < abs(target - result))
                    result = sum;

                if (sum == target)
                    return target;      
                else if (sum < target)
                    left++;           
                else
                    right--;          
            }
        }
        return result;
    }
};
