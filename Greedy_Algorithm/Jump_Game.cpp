/*
Problem: LeetCode 55 – Jump Game


Approach:
1. Keep track of maximum reachable index (maxjump).
2. Traverse the array.
3. If current index is greater than maxjump, return false.
4. Otherwise update maxjump = max(maxjump, i + nums[i]).
5. If traversal completes, return true.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:

    bool canJump(vector<int>& nums) {

        int maxjump = 0;

        for(int i = 0; i < nums.size(); i++){

            if(i > maxjump) return false;

            maxjump = max(maxjump, i + nums[i]);
        }

        return true;
    }
};
