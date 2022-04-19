// https://leetcode.com/problems/longest-turbulent-subarray

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.empty()) return 0;
        int ml = 1;
        int mh = 1;
        int ans = 0;
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            if (arr[i] < arr[i-1]) {
                ml = mh + 1;
                mh = 1;
            } else if (arr[i] > arr[i-1]) {
                mh = ml + 1;
                ml = 1;
            } else {
                ml = 1;
                mh = 1;
            }
            ans = max(ans, max(ml, mh));
        }
        return ans;
    }
};