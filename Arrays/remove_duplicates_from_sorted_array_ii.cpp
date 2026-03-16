/*
Problem: LeetCode 80 – Remove Duplicates from Sorted Array II

Approach:
1. Since the array is sorted, duplicates appear consecutively.
2. Allow at most two occurrences of each element.
3. Maintain a pointer k indicating the position to place the next valid element.
4. Traverse the array starting from index 2.
5. If nums[i] is different from nums[k-2], place it at nums[k] and increment k.
6. Return k as the new length of the array.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
        if(nums.size() < 2) return 1;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] != nums[k - 2]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
