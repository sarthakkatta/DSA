/*
Problem: LeetCode 45 – Jump Game II


Approach:
1. Use greedy approach to track maximum coverage.
2. coverage → farthest index reachable so far.
3. lastJumpIdx → end of current jump range.
4. When current index reaches lastJumpIdx, make a jump and update range.
5. Stop when coverage reaches or passes destination.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:

    int jump(vector<int>& nums) {

        int totalJumps = 0;

        int destination = nums.size() - 1;

        int coverage = 0, lastJumpIdx = 0;

        if(nums.size() == 1) return 0;

        for(int i = 0; i < nums.size(); i++){

            coverage = max(coverage, i + nums[i]);

            if(i == lastJumpIdx){

                lastJumpIdx = coverage;

                totalJumps++;

                if(coverage >= destination){

                    return totalJumps;
                }
            }
        }

        return totalJumps;
    }
};
