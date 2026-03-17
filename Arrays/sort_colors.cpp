/*
Problem: LeetCode 75 – Sort Colors

Approach:
1. Use the Dutch National Flag algorithm.
2. Maintain three pointers: low, mid, and high.
3. If nums[mid] == 0, swap with low and increment both low and mid.
4. If nums[mid] == 1, just move mid forward.
5. If nums[mid] == 2, swap with high and decrement high.
6. Continue until mid crosses high.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
