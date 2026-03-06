/*
Problem: LeetCode 796 – Rotate String


Approach:
1. If lengths of both strings are different, rotation is impossible.
2. Concatenate string s with itself (s + s).
3. If goal is a substring of (s + s), then goal is a rotation of s.
4. Otherwise return false.

Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution{
public:
    bool rotateString(string s, string goal){
        int n = s.length();
        int m = goal.length();

        if(n != m){
            return false;
        }

        if((s + s).find(goal) != string::npos){
            return true;
        }

        return false;
    }
};
