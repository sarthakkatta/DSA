/*
Problem: LeetCode 402 – Remove K Digits

Approach:
- Use a monotonic increasing stack (characters).
- Traverse each digit:
    → While stack top is greater than current digit and k > 0:
        pop from stack (removing bigger digits first gives smaller number).
- Push current digit into stack.
- If k is still left, remove digits from the end.
- Build result from stack.
- Remove leading zeros.
- If empty, return "0".

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for(int i = 0; i < n; i++) {
            // Remove characters from the stack while:
            // - stack is not empty
            // - we still need to remove digits (k > 0)
            // - current digit is smaller than the top of the stack (to maintain increasing order)
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // If we still have digits to remove, remove from the end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        // Build the result string from stack (in reverse order)
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        // Since we built the number in reverse, reverse it to get correct order
        reverse(res.begin(), res.end());
        // Remove leading zeros
        int i = 0;
        while(i < res.size() && res[i] == '0') {
            i++;
        }
        res = res.substr(i); // skip leading zeros
        // If result is empty after removing zeros, return "0"
        if(res.empty()) return "0";
        return res;
    }
};
