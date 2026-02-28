/*
Problem: LeetCode 50 – Pow(x, n)


Approach:
1. Use Binary Exponentiation (Fast Power).
2. Convert n to long long to handle INT_MIN case.
3. If n is negative, convert exponent to positive.
4. If exponent is odd, multiply answer with x.
5. If exponent is even, square x and divide exponent by 2.
6. If original n was negative, return reciprocal of result.

Time Complexity: O(log N)
Space Complexity: O(1)
*/


class Solution{
public:
    double myPow(double x, int n){
        double ans = 1.0;
        long long nn = n;
        if(n < 0) nn = -1 * nn;
        while(nn){
            if(nn % 2 == 1){
                ans = ans * x;
                nn = nn - 1;
            }
            else{
                x = x * x;
                nn = nn / 2;
            }
        }
        if(n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};
