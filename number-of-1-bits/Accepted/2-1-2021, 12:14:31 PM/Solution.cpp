// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t ans = 0;
        uint32_t pow = 1<<31;
        while(pow) {
            ans += (bool)(pow&n);
            pow>>=1;
        }
        return ans;
    }
};