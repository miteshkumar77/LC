// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t fbit = 1; 
        uint32_t bbit = 0x80000000; 
        for (int i = 0; i < 16; ++i) {
            bool r = fbit & n; 
            bool l = bbit & n; 
            
            if (l != r) {
                if (l) {
                    n &= ~bbit;
                } else {
                    n |= bbit; 
                }
                
                if (r) {
                    n &= ~fbit; 
                } else {
                    n |= fbit; 
                }
            }
            fbit = fbit << 1; 
            bbit = bbit >> 1; 
        }
        return n; 
    }
};