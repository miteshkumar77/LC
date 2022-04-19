// https://leetcode.com/problems/partition-array-into-disjoint-intervals

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[n-1];
        vector<int> pref(n+1, INT_MIN);
        for (int i = 0; i < n; ++i) {
            pref[i+1] = max(pref[i], nums[i]);
        }
        int ans = n;
        for (int i = n-1; i > 0; --i) {
            mx = min(mx, nums[i]);
            if (mx >= pref[i]) {
                ans = i;
            }
        }
        return ans;
    }
};