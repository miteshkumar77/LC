// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t pow = 1; 
        int ans = 0; 
        for (int x = 0; x < 32; ++x) {
            ans += !!(n & pow); 
            pow = pow << 1; 
        }
        return ans; 
    }
};