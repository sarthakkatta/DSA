/*
 Problem: Infix to Prefix Conversion
 Platform: GeeksforGeeks

 Approach:
 - Reverse infix string
 - Swap '(' with ')'
 - Convert modified infix to postfix
 - Reverse postfix to get prefix

 Time Complexity: O(N)
 Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
string infixToPostfix(string s) {
    stack<char> st;
    string res = "";
    for(char c : s) {
        // Operand
        if(isalnum(c))
            res += c;
        else if(c == '(')
            st.push(c);
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        // Operator
        else {
            while(!st.empty() && prec(c) <= prec(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

string infixToPrefix(string s) {
    // Step 1: Reverse string
    reverse(s.begin(), s.end());
    // Step 2: Swap brackets
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }
    // Step 3: Infix to Postfix
    string postfix = infixToPostfix(s);
    // Step 4: Reverse postfix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
