// https://leetcode.com/problems/maximum-subarray-min-product

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        //typedef unsigned long long ll;
        typedef int ll;
        int n = nums.size();
        ll ans = 0;
        stack<array<ll, 2>> stk;
        for (int i = 0; i <= n; ++i) {
            array<ll, 2> val{i == n ? (ll)0 : (ll)nums[i], (ll)0};
            while(!stk.empty() && stk.top()[0] >= val[0]) {
                ans = max(ans, (stk.top()[1] + val[1]) * stk.top()[0]);
                val[1] += stk.top()[1];
                stk.pop();
            }
            if (i < n)
                val[1] += nums[i];
            stk.push(val);
        }
        ll M = 1e9 + 7;
        return ans % M;
    }
};