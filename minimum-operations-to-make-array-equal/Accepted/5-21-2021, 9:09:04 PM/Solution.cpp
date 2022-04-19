// https://leetcode.com/problems/minimum-operations-to-make-array-equal

class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        int l = 0;
        int r = n - 1;
        while(l < r) {
            ans += (2 * r-- + 1 - 2 * l++ - 1)/2;
        }
        return ans;
    }
};