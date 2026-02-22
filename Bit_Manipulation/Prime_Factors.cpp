/*
Problem: Find Prime Factors of a Number


Approach:
1. Iterate from 2 to sqrt(n).
2. If i divides n, add it as a prime factor.
3. Divide n completely by i to avoid duplicates.
4. If remaining n > 1, it is also a prime factor.
5. Return all prime factors.

Time Complexity: O(sqrt(N))
Space Complexity: O(1)
*/


class Solution{
public:
    vector<int> primeFactors(int n){
        vector<int> factors;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                factors.push_back(i);
                while(n % i == 0){ // we are doing it jis sie same number multiple times na add krde isliye us se baar baar divifde kr rhe 
                    n /= i;
                }
            }
        }
        if(n != 1){ // agr n abhi bhi bacha h mtlb it itself is a prime factor;
            factors.push_back(n);
        }
        return factors;
    }
};
