// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays

class Solution {
public:
    using ll = long long;
    
    array<vector<ll>, 2> get_max_end(vector<int> const& nums, int k, bool pref) {
        int n = nums.size();
        vector<ll> ans(n+1, INT_MIN);
        vector<ll> idx(n+1, -1);
        ll acc = 0;
        for (int i = 0; i < n; ++i) {
            acc += nums[i];
            if ((i+1) >= k) {
                if ((pref && (ans[i] < acc)) || (!pref && (ans[i] <= acc))) {
                    ans[i+1] = acc;
                    idx[i+1] = (pref ? i-k+1 : n-i-1);
                } else {
                    ans[i+1] = ans[i];
                    idx[i+1] = idx[i];
                }
                acc -= nums[i-k+1];
            }
        }
        return {ans, idx};
    }
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        auto [pref_sum, pref_idx] = get_max_end(nums, k, true);
        reverse(nums.begin(), nums.end());
        auto [suff_sum, suff_idx] = get_max_end(nums, k, false);
        reverse(nums.begin(), nums.end());
        reverse(suff_sum.begin(), suff_sum.end());
        reverse(suff_idx.begin(), suff_idx.end());
        
        ll max_sum = INT_MIN;
        vector<int> ans{};
        
        ll acc{0};
        for (int i = 0; i + k < nums.size(); ++i) {
            acc += nums[i];
            if ((i+1) >= 2 * k) {
                if ((acc + pref_sum[i-k+1] + suff_sum[i+1]) > max_sum) {
                    max_sum = acc + pref_sum[i-k+1] + suff_sum[i+1];
                    ans = {(int)pref_idx[i-k+1], i-k+1, (int)suff_idx[i+1]};
                }
            }
            if ((i+1) >= k) {
                acc -= nums[i-k+1];
            }
        }
        return ans;
        
    }
};