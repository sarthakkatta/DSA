/*
Problem: LeetCode 485 – Max Consecutive Ones

Approach:
1. Traverse the array and maintain a counter for consecutive 1s.
2. If the current element is 1, increment the counter.
3. Update the maximum count whenever a longer streak is found.
4. If the element is 0, reset the counter.
5. Return the maximum consecutive count of 1s.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxcount = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                count++;
                maxcount = max(maxcount, count);
            }else{
                count = 0;
            }
        }
        return maxcount;
    }
};
