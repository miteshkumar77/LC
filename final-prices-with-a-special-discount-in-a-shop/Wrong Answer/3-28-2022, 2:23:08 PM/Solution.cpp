// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<array<int, 3>> vec(n);
        for (int i = 0; i < n; ++i)
            vec[i] = {prices[i], i, -1};
        vector<array<int, 3>> swp(n);
        solve(0, n-1, vec, swp);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (vec[i][2] != -1)
                ans[vec[i][1]] = prices[vec[i][1]] - prices[vec[i][2]];
            else
                ans[vec[i][1]] = prices[vec[i][1]];
        }
        return ans;
    }
    
    void solve(int l, int r, vector<array<int, 3>>& vec, vector<array<int, 3>>& swp) {
        if (l >= r) return;
        int mid = l + (r - l)/2;
        int ls = l;
        int le = mid;
        int rs = mid+1;
        int re = r;
        solve(ls, le, vec, swp);
        solve(rs, re, vec, swp);
        int i = l;
        while(i <= r) {
            if (ls > le) {
                swp[i++] = vec[rs++];
            } else if (rs > re) {
                swp[i++] = vec[ls++];
            } else if (vec[ls][0] >= vec[rs][0]) {
                if (vec[ls][2] == -1) vec[ls][2] = vec[rs][1];
                swp[i++] = vec[ls++];
            } else {
                swp[i++] = vec[rs++];
            }
        }
        for (int i = l; i <= r; ++i) vec[i] = swp[i];
        reverse(vec.begin() + l, vec.begin() + r + 1);
    }
};