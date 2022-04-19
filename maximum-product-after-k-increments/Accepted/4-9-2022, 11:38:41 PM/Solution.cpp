// https://leetcode.com/problems/maximum-product-after-k-increments

class Solution {
public:
    using ll = long long;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i : nums) pq.push(i);
        while(k) {
            ll t = pq.top(); pq.pop();
            pq.push(t+1);
            --k;
        }
        ll M = 1e9 + 7;
        ll a = 1;
        while(!pq.empty()) {
            ll t = pq.top(); pq.pop();
            a = (a * t) % M;
        }
        return a;
    }
};