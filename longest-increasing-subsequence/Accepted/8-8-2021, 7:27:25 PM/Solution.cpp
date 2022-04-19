// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stax;
        int l, r, ans, mid;
        for (int i = 0; i < nums.size(); ++i) {
            l = 0;
            r = (int)stax.size()-1;
            ans = stax.size();
            while(l <= r) {
                mid = l + (r - l)/2;
                if (stax[mid] >= nums[i]) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (ans == stax.size()) {
                stax.push_back(nums[i]);
            } else {
                stax[ans] = nums[i];
            }
        }
        return stax.size();
    }
};