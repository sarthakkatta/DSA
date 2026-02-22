/*
Problem: LeetCode 136 – Single Number


Approach:
1. XOR all elements in array.
2. Same numbers cancel out because a ^ a = 0.
3. Only single occurring number remains.
4. Return the result.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int singleNumber(vector<int>& nums){
        int xorr = 0;
        for(int i = 0; i < nums.size(); i++){
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};
