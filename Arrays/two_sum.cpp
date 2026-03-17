/*
Problem: LeetCode 1 – Two Sum

Approach:
1. Use a hash map to store elements and their indices.
2. Traverse the array and for each element, compute the required complement.
3. Check if the complement exists in the map.
4. If it exists, return the indices.
5. Otherwise, store the current element with its index in the map.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n = nums.size();
        for(int i=0; i<n;i++){
            int num = nums[i];
            int more = target - num;
            if(mpp.find(more) != mpp.end()) {
                return {mpp[more], i};
            }
            mpp[num] = i;
        }
        return {-1,-1};
    }
};
