// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    
    int modpow(int base, int exp, int M) {
        int ans = 1; 
        base = base % M;
        
        for (int i = 0; i < exp; ++i) {
            ans = (ans * base) % M; 
        }
        return ans;
    }
    
    int concatenatedBinary(int n) {
        int M = 1e9 + 7;
        
        int ans = 1;
    
        for (int i = 2; i <= n; ++i) {
            ans = (((unsigned long long int)modpow(2, (int)(log2(i) + 1), M) * ans) % M + i) % M;
        }
        
        
        return ans;
    }
    
};