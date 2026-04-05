/*
Problem: LeetCode 15 – 3Sum

Approach:
1. Sort the array to enable two-pointer technique and handle duplicates.
2. Iterate through the array using index i:
   - Fix nums[i] as the first element.
   - Skip duplicates for i to avoid repeated triplets.
3. Use two pointers:
   - j = i + 1 (left pointer)
   - k = n - 1 (right pointer)
4. Calculate sum = nums[i] + nums[j] + nums[k]:
   - If sum < 0 → move j forward (increase sum)
   - If sum > 0 → move k backward (decrease sum)
   - If sum == 0 → store triplet and move both pointers
5. Skip duplicates for j and k to ensure unique triplets.
6. Return all unique triplets.

Time Complexity: O(N^2)
Space Complexity: O(1) (excluding output)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            //for duplicactes
            if (i != 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;
            }else if(sum > 0){
                k--;
            }else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
        }
        return ans;
    }
};
