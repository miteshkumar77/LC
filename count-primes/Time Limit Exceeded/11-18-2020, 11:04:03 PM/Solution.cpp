// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        
        if (n <= 2) {
            return 0; 
        }
        
        vector<int> primes {2}; 
        
        for (int i = 3; i < n; ++i) {
            bool div = false;
            for (int p : primes) {
                if (i % p == 0) {
                    div = true;
                    break;
                }
            }
            if (!div) {
                primes.push_back(i);
            }
        }
        return primes.size();
        
    }
};