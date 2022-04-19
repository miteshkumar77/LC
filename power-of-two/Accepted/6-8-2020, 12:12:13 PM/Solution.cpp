// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        unsigned long long int k = 1; 
        for (int i = 0; i < sizeof(int) * 8; ++i) {
            if (n == k) {
                return true; 
            }
            
            k = k << 1; 
        }
        return false; 
    }
};