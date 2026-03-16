/*
Problem: LeetCode 268 – Missing Number

Approach:
1. The array contains numbers from 0 to n with exactly one number missing.
2. Compute the expected sum of numbers from 0 to n using the formula n*(n+1)/2.
3. Calculate the sum of all elements present in the array.
4. The difference between the expected sum and the calculated sum gives the missing number.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualsum = n * (n + 1) / 2;
        int calculated = 0;
        for(int i = 0; i < nums.size(); i++){
            calculated += nums[i];
        }
        int ans = actualsum - calculated;
        return ans;
    }
};
