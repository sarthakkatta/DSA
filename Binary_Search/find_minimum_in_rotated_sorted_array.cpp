/*
Problem: Find Minimum in Rotated Sorted Array

Approach:
1. Use Binary Search to locate the minimum element.
2. If the current segment is already sorted, the minimum is at the left boundary.
3. Check which half is sorted:
   - If the left half is sorted, the minimum must be in the right half.
   - Otherwise, the pivot lies in the left half including mid.
4. Keep updating the answer with the smallest candidate found.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            }
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }else{
                high = mid -1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};
