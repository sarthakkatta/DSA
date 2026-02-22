/*
Problem: LeetCode 137 – Single Number II


Approach:
1. Use two variables (ones, twos) to track bits appearing once and twice.
2. When a bit appears first time → add to ones.
3. When it appears second time → move from ones to twos.
4. When it appears third time → remove from both.
5. Remaining bits in ones represent the single occurring number.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int singleNumber(vector<int>& nums){
        int ones = 0;
        int twos = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};
