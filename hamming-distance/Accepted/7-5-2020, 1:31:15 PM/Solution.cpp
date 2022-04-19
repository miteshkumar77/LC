// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0; 
        int bit = 1; 
        for (int i = 0; i < 31; ++i) {
            ans += !!((x & bit) ^ (y & bit)); 
            if (i != 30) { 
                bit = bit << 1; 
            }
        }
        return ans; 
    }
};