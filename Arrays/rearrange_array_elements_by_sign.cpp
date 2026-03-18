/*
Problem: LeetCode 2149 – Rearrange Array Elements by Sign

Approach:
1. Create a result array of the same size.
2. Use two pointers: one for positive indices (even) and one for negative indices (odd).
3. Traverse the input array.
4. Place positive numbers at even indices and negative numbers at odd indices.
5. Increment respective pointers by 2 after placement.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posindex = 0, negindex = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[negindex] = nums[i];
                negindex += 2;
            }else{
                ans[posindex] = nums[i];
                posindex += 2;
            }
        }
        return ans;
    }
};
