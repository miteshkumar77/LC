// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 3) return false;
        while(n > 3) {
            if (n != (n/3) * 3) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};