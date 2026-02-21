/*
Problem: LeetCode 435 – Non-overlapping Intervals

Approach:
1. Sort intervals based on end time.
2. Select first interval and store its end time.
3. Traverse remaining intervals.
4. If current interval start >= last end, update last end.
5. Otherwise, increment removal count.
6. Return total intervals removed.

Time Complexity: O(N log N)
Space Complexity: O(1)
*/


class Solution{
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 0;
        int lastEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= lastEnd){
                lastEnd = intervals[i][1];
            }
            else{
                cnt += 1;
            }
        }
        return cnt;
    }
};
