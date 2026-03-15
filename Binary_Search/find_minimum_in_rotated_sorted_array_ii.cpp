/*
Problem: Find Minimum in Rotated Sorted Array II

Approach:
1. Use Binary Search to find the minimum element in the rotated array.
2. If the current segment is sorted, the minimum is at the left boundary.
3. If duplicates appear at low, mid, and high, shrink the search space.
4. Determine which half is sorted and move the search accordingly.
5. Keep updating the minimum candidate during the process.

Time Complexity: O(log N) on average, O(N) in worst case due to duplicates
Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If current segment is sorted
            if (nums[low] < nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            // When duplicates are present
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ans = min(ans, nums[low]);
                low++;
                high--;
            }

            else if (nums[low] <= nums[mid]) {
                // Left half is sorted
                ans = min(ans, nums[low]);
                low = mid + 1;
            }

            else {
                // Right half contains pivot
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};
