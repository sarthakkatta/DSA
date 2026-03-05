/*
Problem: LeetCode 14 – Longest Common Prefix


Approach:
1. If array is empty, return empty string.
2. Sort the array of strings.
3. Compare the first and last string after sorting.
4. Count matching characters from the beginning.
5. Return the common prefix substring.

Time Complexity: O(N log N + M)
Space Complexity: O(1)
*/


class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        int i = 0;
        while(i < first.size() && first[i] == last[i]){
            i++;
        }

        return first.substr(0, i);
    }
};
