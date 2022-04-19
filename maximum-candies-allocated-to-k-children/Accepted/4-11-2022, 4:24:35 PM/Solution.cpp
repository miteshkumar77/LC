// https://leetcode.com/problems/maximum-candies-allocated-to-k-children

class Solution {
public:
    using ll = long long;
    bool check(vector<int> const& c, ll k, ll lim) {
        for (int i : c) {
            k -= (int)(i/lim);
            if (k <= 0) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, ll k) {
        ll l = 1;
        ll r = *max_element(begin(candies), end(candies));
        ll mid;
        ll ans=0;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(candies, k, mid)) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};