// https://leetcode.com/problems/bulb-switcher

class Solution {
public:
    int bulbSwitch(int n) {
        int l = 0;
        int r = n;
        int ans = 0;
        while(l <= r) {
            int mid = l + (r - l)/2;
            unsigned long long int sq = mid * mid;
            if (sq > n) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};