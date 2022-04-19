// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(long long c) {
        for (long long i = 0; i * i <= c; ++i) {
            long long tmp = sqrt(c - i * i);
            if (tmp * tmp == c - i * i) return true;
        }
        return false;
    }
};