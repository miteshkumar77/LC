// https://leetcode.com/problems/132-pattern

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = min(pre[i - 1], nums[i]);
        }
        
        int suf = nums.back();
        for (int j = n - 2; j > 0; --j) {
            if (nums[j] > suf && nums[j] > pre[j - 1]) {
                return true;
            }
            suf = min(nums[j], suf);
        }
        return false;
    }
};