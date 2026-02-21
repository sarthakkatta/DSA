/*
Problem: LeetCode 56 – Merge Intervals


Approach:
1. Sort intervals based on start time.
2. Traverse each interval.
3. If merged list is empty or no overlap, add interval.
4. If overlap exists, merge by updating end time.
5. Return merged intervals.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/


class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); i++){
            vector<int>& interval = intervals[i];
            if(merged.empty() || interval[0] > merged.back()[1]){
                merged.push_back(interval);
            }
            else{
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
