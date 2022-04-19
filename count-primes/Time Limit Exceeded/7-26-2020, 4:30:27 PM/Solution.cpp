// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0; 
        }
        
        
        int ans = 1; 
        
        for (int i = 3; i < n; i += 2) {
            bool found = true; 
            for (int j = 3; j < i; j += 2) {
                if (i % j == 0) {
                    found = false;
                    break;
                }
            }
            ans += found; 
        }
        return ans; 
    }
};