/*
Problem: LeetCode 1106 – Parsing A Boolean Expression

Approach:
1. Use stack to process expression.
2. Push characters until ')' is found.
3. When ')' appears → evaluate expression inside brackets.
4. Count number of true (t) and false (f).
5. Apply operator (!, &, |) and push result back.
6. Final stack top gives answer.

Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution {
public:
    bool parseBoolExpr(string expression) {

        stack<char> st;

        for(char ch : expression) {

            // ignore commas
            if(ch == ',') continue;

            // if not closing bracket, push
            if(ch != ')') {
                st.push(ch);
            }
            else {

                // evaluate expression inside ()
                int t = 0, f = 0;

                // count true and false
                while(st.top() != '(') {

                    if(st.top() == 't') t++;
                    else f++;

                    st.pop();
                }

                // remove '('
                st.pop();

                // operator
                char op = st.top();
                st.pop();

                // evaluate based on operator
                if(op == '!') {

                    if(f == 1)
                        st.push('t');
                    else
                        st.push('f');
                }
                else if(op == '&') {

                    if(f > 0)
                        st.push('f');
                    else
                        st.push('t');
                }
                else if(op == '|') {

                    if(t > 0)
                        st.push('t');
                    else
                        st.push('f');
                }
            }
        }

        return st.top() == 't';
    }
};
