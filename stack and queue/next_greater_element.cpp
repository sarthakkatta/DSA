/*
 Problem: Next Greater Element I

 Approach:
 - Use monotonic stack on nums2 (from right to left)
 - Store next greater of each element in hashmap
 - For nums1, directly fetch answers from map

 Time Complexity: O(N + M)
 Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!s.empty() && nums2[i] >= s.top()) {
                s.pop();
            }
            if(s.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};
