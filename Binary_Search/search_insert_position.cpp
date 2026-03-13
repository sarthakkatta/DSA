/*
Problem: LeetCode 35 – Search Insert Position

Approach:
1. Use Binary Search on the sorted array.
2. Maintain two pointers: low and high.
3. If nums[mid] equals target, return mid.
4. If nums[mid] < target, move low to mid + 1.
5. Otherwise move high to mid - 1.
6. If the target is not found, low will indicate the correct insertion index.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};
