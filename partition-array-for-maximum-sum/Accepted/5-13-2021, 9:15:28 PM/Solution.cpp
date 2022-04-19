// https://leetcode.com/problems/partition-array-for-maximum-sum

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        int prev;
        int mxelem;
        for (int i = 0; i < n; ++i) {
            mxelem = arr[i];
            for (int j = i; j >= max(0, i - k + 1); --j) {
                mxelem = max(mxelem, arr[j]);
                prev = (j == 0) ? 0 : dp[j-1];
                dp[i] = max(dp[i], mxelem * (i - j + 1) + prev);
            }
        }
        return dp.back();
    }
};