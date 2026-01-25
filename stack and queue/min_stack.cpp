/*
 Problem: Min Stack

 Concept:
 - Stack supports push, pop, top and getMin in O(1)
 - Uses encoding technique:
     When pushing smaller value than current min:
     push(2*val - min) and update min

 Time Complexity:
   push → O(1)
   pop  → O(1)
   top  → O(1)
   getMin → O(1)

 Space Complexity: O(N)
*/

class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
        min = INT_MAX;
    }
    void push(int val) {
        long long value = val;
        if(st.empty()){
            min = value;
            st.push(value);
        } else {
            if(value >= min) st.push(value);
            else {
                st.push(2 * value - min);
                min = value;
            }
        }
    }
    void pop() {
        if(st.empty()) return;
        long long val = st.top();
        st.pop();
        if(val < min){
            min = 2 * min - val;
        }
    }
    int top() {
        if (st.empty()) return -1;
        long long val = st.top();
        if (val < min) {
            return (int)min; 
        }
        return (int)val;
    }
    int getMin() {
        if (st.empty()) return -1;
        return (int)min;
    }
};
