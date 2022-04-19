// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int suff = accumulate(nums.begin(), nums.end(), 0);
        int pref = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            suff -= nums[i];
            // cout << suff << ": " << (n - i - 1) << ' ' << pref << ": " << i << endl;
            ans[i] = abs(suff - (n - i - 1) * nums[i]) + abs(pref - i * nums[i]);
            pref += nums[i];

        }
        return ans;
        
    }
};