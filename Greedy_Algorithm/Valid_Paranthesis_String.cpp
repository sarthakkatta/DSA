/*
Problem: LeetCode 678 – Valid Parenthesis String


Approach:
1. Use two stacks:
   - openStack → stores indices of '('
   - starStack → stores indices of '*'
2. Traverse string:
   - If '(', push to openStack.
   - If '*', push to starStack.
   - If ')', try matching with '(' first, otherwise with '*'.
   - If neither available, return false.
3. After traversal, match remaining '(' with '*' that appear after them.
4. If any '(' remains unmatched, return false.

Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack;
        stack<int> starStack;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                openStack.push(i);
            }
            else if(s[i] == '*'){
                starStack.push(i);
            }
            else if(s[i] == ')'){
                if(!openStack.empty()){
                    openStack.pop();
                }
                else if(!starStack.empty()){
                    starStack.pop();
                }
                else{
                    return false;
                }
            }
        
        while(!openStack.empty() && !starStack.empty()){
            if(openStack.top() < starStack.top())
                openStack.pop();
                starStack.pop();
            }
            else{
                return false;
            }
        }
        return openStack.empty();
    }
};
