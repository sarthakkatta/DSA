/*
Problem: LeetCode 560 – Subarray Sum Equals K

Approach:
1. Use Prefix Sum with a Hash Map.
2. Maintain a running prefix sum while traversing the array.
3. For each index, check if (prefixsum - k) exists in the map.
4. If it exists, add its frequency to the count.
5. Store/update the current prefix sum in the map.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int prefixsum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixsum += nums[i];
            if(mp.find(prefixsum - k) != mp.end())
                count += mp[prefixsum - k];
            mp[prefixsum]++;
        }
        return count;
    }
};
