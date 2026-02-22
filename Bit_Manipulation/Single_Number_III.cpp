/*
Problem: LeetCode 260 – Single Number III


Approach:
1. XOR all elements to get xorall = num1 ^ num2.
2. Find rightmost set bit in xorall to differentiate two numbers.
3. Divide numbers into two groups based on that bit.
4. XOR each group separately to get the two unique numbers.
5. Return both numbers.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    vector<int> singleNumber(vector<int>& nums){
        long xorall = 0;
        for(int i = 0; i < nums.size(); i++) xorall = xorall ^ nums[i];
        int rightmost = (xorall & (xorall - 1)) ^ xorall;
        int b1 = 0, b2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & rightmost) b1 ^= nums[i];
            else b2 ^= nums[i];
        }
        return {b1, b2};
    }
};
