/*
Problem: LeetCode 18 – 4Sum

Approach:
1. Sort the array to simplify handling duplicates and use two-pointer technique.
2. Use two nested loops:
   - First loop (i) fixes the first element.
   - Second loop (j) fixes the second element.
   - Skip duplicates for both i and j.
3. Use two pointers:
   - k = j + 1 (left pointer)
   - l = n - 1 (right pointer)
4. Compute sum of four elements using long long to avoid overflow.
5. Compare sum with target:
   - If sum == target → store quadruplet, move both pointers.
   - If sum < target → move k forward.
   - If sum > target → move l backward.
6. Skip duplicates for k and l to ensure unique quadruplets.
7. Return all unique quadruplets.

Time Complexity: O(N^3)
Space Complexity: O(1) (excluding output)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i - 1]) continue;
            for(int j = i+1;j<n;j++){
                if(j != i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = n - 1;
                while(k < l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k - 1]) k++;
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};
