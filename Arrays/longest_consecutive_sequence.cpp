/*
Problem: LeetCode 128 – Longest Consecutive Sequence

Approach:
1. Insert all elements into an unordered set for O(1) lookup.
2. Iterate through the set and check for the start of a sequence (element whose previous is not present).
3. From each starting point, count consecutive elements.
4. Update the maximum length found.

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int num : arr){
        st.insert(num);
    }
    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x + 1) != st.end()){
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
