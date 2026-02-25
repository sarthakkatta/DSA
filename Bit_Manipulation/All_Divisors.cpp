/*
Problem: Find All Divisors of a Number


Approach:
1. Iterate from 1 to sqrt(n).
2. If i divides n, add i as divisor.
3. If n/i is different from i, add n/i.
4. Sort all divisors in ascending order.
5. Return the list of divisors.

Time Complexity: O(sqrt(N) + D log D)
Space Complexity: O(D)
*/


class Solution{
public:
    vector<int> allDivisors(int n){
        vector<int> divisors;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                divisors.push_back(i);
                if(n / i != i)
                    divisors.push_back(n / i);
            }
        }
        sort(divisors.begin(), divisors.end());
        return divisors;
    }
};
