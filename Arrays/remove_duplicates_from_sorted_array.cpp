/*
Problem: LeetCode 26 – Remove Duplicates from Sorted Array

Approach:
1. Use the Two Pointer technique.
2. Maintain pointer i for the position of the last unique element.
3. Traverse the array with pointer j.
4. Whenever nums[j] is different from nums[i], move i forward and place nums[j] at nums[i].
5. The new length of the array is i + 1.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        for(int j = 1; j < n; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
