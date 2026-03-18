/*
Problem: LeetCode 53 – Maximum Subarray

Approach:
1. Use Kadane’s Algorithm.
2. Traverse the array while maintaining a running sum.
3. Update the maximum sum whenever the current sum is greater.
4. If the running sum becomes negative, reset it to 0.
5. The maximum value obtained is the answer.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxi = nums[0];
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxi = max(sum, maxi);
            if(sum <  0) sum = 0;
        }
        return maxi;
    }
};
