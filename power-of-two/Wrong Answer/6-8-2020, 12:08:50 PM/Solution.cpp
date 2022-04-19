// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int k = 1; 
        cout << k << endl; 
        for (int i = 0; i < sizeof(int); ++i) {
            if (n == k) {
                return true; 
            }
            k = k << 1; 
        }
        return false; 
    }
};