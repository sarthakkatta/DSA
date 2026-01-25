/*
 Problem: Valid Parentheses

 Concept:
 - Use stack to track opening brackets
 - On encountering closing bracket:
     → stack top must match
 - Finally stack should be empty

 Time Complexity: O(N)
 Space Complexity: O(N)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
