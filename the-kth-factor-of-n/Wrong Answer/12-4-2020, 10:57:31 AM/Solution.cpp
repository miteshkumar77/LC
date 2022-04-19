// https://leetcode.com/problems/the-kth-factor-of-n

class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        int factor = 1;
        while(i != k) {
            if (n % factor == 0) {
                ++i;
            }
            ++factor;
        }
        return factor;
    }
};