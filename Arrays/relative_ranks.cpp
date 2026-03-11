/*
Problem: LeetCode 506 – Relative Ranks

Approach:
1. Store each score with its original index.
2. Sort the scores in descending order.
3. Traverse the sorted list and assign ranks.
4. Place the rank/medal at the original index in the result array.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({score[i], i});
        }

        sort(arr.begin(), arr.end(), greater<pair<int,int>>());

        vector<string> ans(n);

        for(int i = 0; i < n; i++){
            int idx = arr[i].second;

            if(i == 0) ans[idx] = "Gold Medal";
            else if(i == 1) ans[idx] = "Silver Medal";
            else if(i == 2) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(i + 1);
        }

        return ans;
    }
};
