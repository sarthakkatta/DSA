/*
Problem: LeetCode 455 – Assign Cookies


Approach:
1. Sort both greed factor array (g) and cookie size array (s).
2. Use two pointers:
   - left → points to current cookie
   - right → points to current child
3. If current cookie can satisfy current child, move both pointers.
4. Otherwise, try next larger cookie.
5. Number of satisfied children is stored in right pointer.

Time Complexity: O(N log N + M log M)
Space Complexity: O(1)
*/


class Solution {
public:

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int left = 0, right = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(left < s.size() && right < g.size()){
            if(g[right] <= s[left]){
                right++;
            }
            left++;
        }

        return right;
    }
};
