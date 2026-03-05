/*
Problem: LeetCode 205 – Isomorphic Strings


Approach:
1. Use two arrays to store last seen positions of characters.
2. If the last seen positions of current characters differ, strings are not isomorphic.
3. Update the last seen position for both characters.
4. If all mappings match, return true.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    bool isIsomorphic(string s, string t){
        int indexS[200] = {0};
        int indexT[200] = {0};
        if(s.length() != t.length()) return false;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(indexS[s[i]] != indexT[t[i]]){
                return false;
            }
            indexS[s[i]] = i + 1;
            indexT[t[i]] = i + 1;
        }
        return true;
    }
};
