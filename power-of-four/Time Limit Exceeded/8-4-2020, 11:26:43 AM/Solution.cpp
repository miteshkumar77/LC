// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num != 1) {
            if (num % 4 != 0) {
                return false; 
            }
            num /= 4; 
        }
        return true; 
    }
};