/*
Problem: LeetCode 2016 – Maximum Difference Between Increasing Elements

Approach:
1. Track minimum value seen so far (mini).
2. Traverse the array:
   - Update mini = min(mini, nums[i]).
   - If current element > mini:
       → compute difference = nums[i] - mini
       → update answer.
3. If no valid increasing pair found → return -1.

Key Idea:
- Keep track of smallest element before current index.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = INT_MAX;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            mini = min(mini,nums[i]);
            if(nums[i] > mini) ans = max(ans, nums[i] - mini);
        }
        return ans;
    }
};
