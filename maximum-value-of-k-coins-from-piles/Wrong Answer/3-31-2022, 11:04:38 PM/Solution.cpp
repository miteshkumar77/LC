// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> suff(n, vector<int>(k, 0));
        vector<int> idx(n, 0);
        for (int p = 0; p < n; ++p) {
            int prev = 0;
            for (int i = 0; i < min(k, (int)piles[p].size()); ++i) {
                prev += piles[p][i];
                suff[p][i] = prev;
            }
        }
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            int pile = -1;    
            int amt = INT_MIN;
            for (int p = 0; p < n; ++p) {
                if (amt < suff[p][k - i - 1]) {
                    amt = suff[p][k - i - 1];
                    pile = p;
                }
            }
            ans += piles[pile][idx[pile]];
            for (int j = 0; j + 1 < suff[pile].size(); ++j) {
                suff[pile][j] = suff[pile][j+1] - piles[pile][idx[pile]];
            }
            ++idx[pile];
        }
        return ans;
    }
};