// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0; 
        }
        vector<bool> isprime(n, true); 
        for (int i = 3; i < n; i += 2) {
            for (int j = 3; j * i < n; j += 2) {
                isprime[j * i] = false; 
            }
        }
        
         
        int ans = 0; 
        for (int i = 0; i < n; ++i) {
            ans += ((i % 2 != 0) && isprime[i]);
        }
        
        return ans; 
    }
};