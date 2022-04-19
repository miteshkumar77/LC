// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    bool check(vector<int> const& weights, int days, int w) {
        int d = 1;
        int c = 0;
        for (int i : weights) {
            if (c + i > w) {
                c = 0;
                if (++d > days) return false;
            }
            c += i;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1;
        int r = accumulate(weights.begin(), weights.end(), 0);
        int mid;
        int ans = r;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(weights, days, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};