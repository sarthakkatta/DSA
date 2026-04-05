/*
Problem: LeetCode 229 – Majority Element II

Approach:
1. Use Boyer-Moore Voting Algorithm (extended version).
2. At most 2 elements can appear more than ⌊n/3⌋ times.
3. First pass:
   - Find two potential candidates (el1, el2) using counters.
   - Increase/decrease counts based on matching or mismatch.
4. Second pass:
   - Count actual frequency of both candidates.
5. Add elements to result if their count ≥ (n/3 + 1).
6. Sort result before returning.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1 = 1;
                el1 = nums[i];
            }else if(cnt2 == 0 && nums[i] != el1){
                 cnt2 = 1;
                 el2 = nums[i];
            }else if(nums[i] == el1){
                cnt1++;
            }else if(nums[i] == el2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ls;
        cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (el1 == nums[i]) cnt1++;
            if (el2 == nums[i]) cnt2++;
        }

        int mini = (int)(nums.size() / 3) + 1; 

        if (cnt1 >= mini) ls.push_back(el1);
        if (cnt2 >= mini && el2 != el1) ls.push_back(el2);

        sort(ls.begin(), ls.end());
        return ls;
    }
};
