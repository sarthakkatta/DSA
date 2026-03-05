/*
Problem: LeetCode 1021 – Remove Outermost Parentheses


Approach:
1. Maintain a counter for open parentheses.
2. Decrease counter when encountering ')'.
3. Add character to result only if counter is not zero.
4. Increase counter when encountering '('.
5. This skips the outermost parentheses of each primitive group.

Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution{
public:
    string removeOuterParentheses(string s){
        int cnt = 0;
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                cnt--;
            }
            if(cnt != 0){
                ans += s[i];
            }
            if(s[i] == '('){
                cnt++;
            }
        }
        return ans;
    }
};
