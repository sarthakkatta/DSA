/*
Problem: LeetCode 227 – Basic Calculator II

Approach:
1. Use stack to handle operator precedence.
2. Maintain:
   - num → current number
   - op  → previous operator
3. Traverse string:
   - Build multi-digit numbers.
4. When operator or end of string is reached:
   - If op == '+':
       → push num
   - If op == '-':
       → push -num
   - If op == '*':
       → multiply with stack top
   - If op == '/':
       → divide stack top by num
5. Update current operator and reset num.
6. Sum all values in stack for final answer.

Key Idea:
- Stack handles multiplication/division immediately,
  while addition/subtraction are resolved later.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long num = 0;
        char op = '+';
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            // build number
            if(ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
            }
            // operator OR last character
            if((ch != ' ' && !(ch >= '0' && ch <= '9')) || i == s.size() - 1) {
                if(op == '+') {
                    st.push(num);
                }
                else if(op == '-') {
                    st.push(-num);
                }
                else if(op == '*') {
                    int top = st.top();
                    st.pop();

                    st.push(top * num);
                }
                else if(op == '/') {
                    int top = st.top();
                    st.pop();

                    st.push(top / num);
                }
                op = ch;
                num = 0;
            }
        }
        int result = 0;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
