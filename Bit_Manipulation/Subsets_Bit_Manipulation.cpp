/*
Problem: LeetCode 78 – Subsets


Approach:
1. Total subsets for n elements = 2^n.
2. Use numbers from 0 to (2^n - 1) as bitmasks.
3. For each mask, check which bits are set.
4. If j-th bit is set, include nums[j] in subset.
5. Store each subset in result and return.

Time Complexity: O(N * 2^N)
Space Complexity: O(N * 2^N)
*/


class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        int n = nums.size();
        int total = 1 << n;
        vector<vector<int>> ans;
        for(int mask = 0; mask < total; mask++){
            vector<int> subset;
            for(int j = 0; j < n; j++){
                if(mask & (1 << j)){
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
