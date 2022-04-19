// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k

class Solution {
public:
    int subarrsum(vector<vector<int>>& bmatrix, int k, int l, int r) {
        set<int> p{0};
        int n = bmatrix.size();
        int pr = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            pr += bmatrix[i][r] - bmatrix[i][l];
            auto it = p.lower_bound(pr - k);
            if (it != p.end()) {
                ans = max(ans, pr - *it);
            }
            p.insert(pr);
        }
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); int m = matrix[0].size();
        vector<vector<int>> bmatrix(n, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                bmatrix[i][j] = matrix[i][j-1] + bmatrix[i][j-1];
            }
        }
        int ans = INT_MIN;
        for (int l = 0; l < m; ++l) {
            for (int r = l+1; r <= m; ++r) {
                ans = max(ans, subarrsum(bmatrix, k, l, r));
            }
        }
        return ans;
    }
};