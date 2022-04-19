// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
public:
    int numOfWays(int n) {
        unsigned long long int a121 = 6; 
        unsigned long long int a123 = 6; 
        unsigned long long int b121 = 6; 
        unsigned long long int b123 = 6; 
        
        int mod = 1e9 + 7; 
        for (int i = 2; i <= n; ++i) {
            b121 = (3 * a121 + 2 * a123) % mod;
            b123 = (2 * a121 + 2 * a123) % mod; 
            
            a123 = b123; 
            a121 = b121; 
        }
        
        return (a121 + a123) % mod; 
    }
};