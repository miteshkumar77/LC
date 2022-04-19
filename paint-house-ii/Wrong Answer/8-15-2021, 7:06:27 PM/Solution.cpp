// https://leetcode.com/problems/paint-house-ii

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int m1, m2;
        int n = costs.size(); int k = costs[0].size();
        if (k == 1) return INT_MAX;
        for (int h = 1; h <= n; ++h) {
            m1 = -1; m2 = -1;
            for (int c = 0; c < k; ++c) {
                if (m1 == -1 || costs[h-1][m1] > costs[h-1][c]) {
                    m2 = m1;
                    m1 = c;
                } else if (m2 == -1 || costs[h-1][m2] > costs[h-1][c]) {
                    m2 = c;
                }
            }
            if (h != n) {
                for (int c = 0; c < k; ++c) {
                    
                    if (m1 != c) {
                        costs[h][c] += costs[h-1][m1];
                    } else {
                        costs[h][c] += costs[h-1][m2];
                    }
                }
            }
        }
        return costs[n-1][m1];
    }
};