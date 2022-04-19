// https://leetcode.com/problems/broken-calculator

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while(Y > X) {
            if (Y % 2 == 0) {
                Y >>= 1;
            } else {
                Y += 1;
            }
            ++ans;
        }
        return ans + X - Y; 
    }
};