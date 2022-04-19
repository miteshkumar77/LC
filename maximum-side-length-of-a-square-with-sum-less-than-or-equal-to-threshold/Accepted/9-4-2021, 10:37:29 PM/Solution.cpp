// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold

class Solution {
public:
    bool check(int s, vector<vector<int>>& sum, int n, int m, int target) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i >= s && j >= s && sum[i][j] - sum[i-s][j] - sum[i][j-s] + sum[i-s][j-s] <= target) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(); int m = mat[0].size();
        vector<vector<int>> sum(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = mat[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        
        int ans = 0;
        int l = 0; int r = min(n, m);
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(mid, sum, n, m, threshold)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
        
    }
};