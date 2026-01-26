/*
 Problem: Postfix to Infix Conversion

 Approach:
 - Use stack of strings
 - For every operand → push to stack
 - For every operator:
     → pop two operands
     → form "(op1 operator op2)"
     → push back

 Time Complexity: O(N)
 Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;
// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> s;
    int n = postfix.size();
    for (int i = 0; i < n; i++) {
        char c = postfix[i];
        // Operand
        if (isalnum(c)) {
            s.push(string(1, c));
        }
        // Operator
        else {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            s.push("(" + op1 + c + op2 + ")");
        }
    }
    return s.top();
}
