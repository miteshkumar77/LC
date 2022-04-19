// https://leetcode.com/problems/broken-calculator

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (target > startValue && target % 2 == 0) return 1 + brokenCalc(startValue, target/2);
        if (target == startValue) return 0;
        return 1 + brokenCalc(startValue, target + 1);
    }
};