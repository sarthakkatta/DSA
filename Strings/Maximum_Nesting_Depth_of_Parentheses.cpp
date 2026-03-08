/*
Problem: LeetCode 1614 – Maximum Nesting Depth of the Parentheses


Approach:
1. Traverse the string character by character.
2. Increase current depth when '(' is encountered.
3. Update maximum depth.
4. Decrease current depth when ')' is encountered.
5. Return the maximum depth found.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int maxDepth(string s){
        int res = 0, cur = 0;
        for(char &c : s){
            if(c == '('){
                cur++;
                res = max(cur, res);
            }
            if(c == ')'){
                cur--;
            }
        }
        return res;
    }
};
