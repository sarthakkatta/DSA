/*
Problem: LeetCode 204 – Count Primes


Approach:
1. Use Sieve of Eratosthenes to mark prime numbers.
2. Initialize array with all values as prime.
3. For each number from 2 to sqrt(n), mark its multiples as non-prime.
4. Count all remaining prime numbers less than n.
5. Return the count.

Time Complexity: O(N log log N)
Space Complexity: O(N)
*/


class Solution{
public:
    int countPrimes(int n){
        if(n <= 2) return 0;
        vector<int> prime(n, 1);
        for(int i = 2; i * i <= n; i++){
            if(prime[i] == 1){
                for(int j = i * i; j < n; j += i) prime[j] = 0;
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(prime[i] == 1) count++;
        }
        return count;
    }
};
