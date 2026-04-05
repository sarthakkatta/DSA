/*
Problem: LeetCode 56 – Merge Intervals

Approach:
1. Sort all intervals based on starting time.
2. Initialize an empty result vector `merged`.
3. Traverse each interval:
   - If `merged` is empty OR current interval does not overlap 
     (start > last merged end), push it to result.
   - Otherwise, merge the intervals by updating the end time:
     merged.back()[1] = max(current end, last merged end).
4. Return the merged intervals.

Time Complexity: O(N log N)  (due to sorting)
Space Complexity: O(N)       (for storing result)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for(int i=0;i < intervals.size(); i++){
            vector<int>& interval = intervals[i];
            if(merged.empty() || interval[0] > merged.back()[1]){
                merged.push_back(interval);
            }else{
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
