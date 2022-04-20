class Solution {
public:
    using ll = long long;
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<ll> lls(nums.begin(), nums.end());
        vector<ll> ans;
        for (ll i : lls) {
            ans.push_back(i);
            size_t n = ans.size();
            while(n >= 2) {
                ll g = __gcd(ans[n-1], ans[n-2]);
                if (g == 1) break;
                ans[n-2] = (ans[n-1] * ans[n-2])/g;
                ans.pop_back();
                --n;
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};