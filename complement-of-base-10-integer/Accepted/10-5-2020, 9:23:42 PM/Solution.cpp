// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int N) {
        
        if (N == 0) {
            return 1;
        }
        int save = N;
        int pow = 1;
        while(save != 0) {
            save >>= 1;
            pow <<= 1;
        }
        
        pow >>= 1;
        
        
        while(pow != 0) {
            N ^= pow;
            pow >>= 1;
        }
        return N;
        
        
    }
};