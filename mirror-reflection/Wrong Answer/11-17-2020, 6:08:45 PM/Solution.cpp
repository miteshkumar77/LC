// https://leetcode.com/problems/mirror-reflection

class Solution {
public:
    int mirrorReflection(int p, int q) {
        if (q == p/2 && p % 2 == 0) {
            return 2;
        } else if (q > p/2) {
            return 1;
        } else {
            return 0;
        }
    }
};