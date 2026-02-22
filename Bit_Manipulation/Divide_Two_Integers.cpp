/*
Problem: LeetCode 29 – Divide Two Integers


Approach:
1. Handle overflow case when dividend = INT_MIN and divisor = -1.
2. Determine sign of result based on dividend and divisor.
3. Convert both numbers to positive long values.
4. Use bit shifting to subtract largest multiple of divisor.
5. Add corresponding power of 2 to quotient.
6. Apply sign and return result.

Time Complexity: O(log N)
Space Complexity: O(1)
*/


class Solution{
public:
    int divide(int dividend, int divisor){
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(dividend == divisor)
            return 1;
        bool sign = true;
        if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = false;
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long quotient = 0;
        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt + 1))){
                cnt += 1;
            }
            quotient += 1 << cnt;
            n -= (d << cnt);
        }
        if(quotient == (1L << 31) && sign){
            return INT_MAX;
        }
        if(quotient == (1L << 31) && !sign){
            return INT_MIN;
        }
        return sign ? quotient : -quotient;
    }
};
