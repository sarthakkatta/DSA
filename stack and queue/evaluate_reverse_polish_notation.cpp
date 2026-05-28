/*
Problem: LeetCode 150 – Evaluate Reverse Polish Notation

Approach:
1. Use stack to evaluate postfix expression.
2. Traverse tokens:
   - If token is a number:
       → push into stack.
   - Else token is an operator:
       → pop top two elements.
       → perform operation.
       → push result back into stack.
3. Order matters:
   - a = second top element
   - b = top element
   - perform a op b
4. Final answer remains at top of stack.

Key Idea:
- Postfix expressions are naturally solved using stack.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if(s == "+") st.push(a + b);
                else if(s == "-") st.push(a - b);
                else if(s == "*") st.push(a * b);
                else st.push(a / b);
            }
            else {
                // number
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
