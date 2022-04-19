// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n > 1) {
            if (n != (n/3) * 3) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};