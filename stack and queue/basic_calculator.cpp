/*
Problem: LeetCode 224 – Basic Calculator

Approach:
1. Maintain:
   - result → current evaluated value
   - number → current number being formed
   - sign → +1 or -1
2. Traverse string:
   - If digit:
       → build multi-digit number.
   - If '+' or '-':
       → add previous number using sign.
       → update sign.
3. For '(':
   - Push current result and sign into stack.
   - Reset result and sign for new expression.
4. For ')':
   - Complete current bracket expression.
   - Multiply with stored sign.
   - Add to previous result.
5. Add leftover number at end.
6. Return final result.

Key Idea:
- Stack stores state before entering brackets.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int number = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            // digit
            if(isdigit(ch)) {
                number = number * 10 + (ch - '0');
            }
            // plus
            else if(ch == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }
            // minus
            else if(ch == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }
            // opening bracket
            else if(ch == '(') {
                // save old result
                st.push(result);
                // save sign
                st.push(sign);
                // reset
                result = 0;
                sign = 1;
            }
            // closing bracket
            else if(ch == ')') {
                // complete current bracket expression
                result += sign * number;
                number = 0;
                // sign before bracket
                int prevSign = st.top();
                st.pop();
                // result before bracket
                int prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }
        // leftover number
        result += sign * number;
        return result;
    }
};
