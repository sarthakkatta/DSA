/*
Problem: LeetCode 704 – Binary Search

Approach:
1. Use Binary Search on the sorted array.
2. Initialize two pointers: low at start and high at end.
3. Calculate mid and compare nums[mid] with target.
4. If equal, return the index.
5. If nums[mid] > target, search in the left half.
6. Otherwise search in the right half.
7. If the loop ends, the target is not present.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) 
                return mid;
            else if(nums[mid] > target) 
                high = mid - 1;
            else 
                low = mid + 1;
        }

        return -1;
    }
};
