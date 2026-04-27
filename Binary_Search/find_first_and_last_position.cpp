/*
Problem: LeetCode 34 – Find First and Last Position of Element in Sorted Array

Approach:
1. Use Binary Search twice to find the first and last occurrence of the target.
2. For the first occurrence, move the search toward the left whenever nums[mid] >= target.
3. For the last occurrence, move the search toward the right whenever nums[mid] <= target.
4. Store the index whenever the target is found.
5. Return both indices as the result.

Time Complexity: O(log N) 
Space Complexity: O(1)
*/

class Solution {
public:
    int lower(vector<int> nums, int target, int low, int high) {
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
                ans = mid;
            if(nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }

    int upper(vector<int> nums, int target, int low, int high) {
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
                ans = mid;
            if(nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower(nums, target, 0, nums.size()-1), upper(nums, target, 0, nums.size()-1)};
    }
};
