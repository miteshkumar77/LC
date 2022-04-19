// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
    int cal(vector<int>& value, vector<vector<int>>& mat, int rho) {
        if (value[rho] == -1) {
            int l = 0;
            int r = mat[0].size() - 1;
            int mid;
            int ans = r + 1;
            while(l <= r) {
                mid = l + (r - l)/2;
                if (mat[rho][mid]) {
                    l = mid + 1;
                } else {
                    ans = mid;
                    r = mid - 1;
                }
            }
            value[rho] = ans;
        }
        return value[rho]; 
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(); 
        vector<int> value(n, -1); 
        vector<int> subarr(n);
        for (int i = 0; i < n; ++i) {
            subarr[i] = i;
        }
        sort(subarr.begin(), subarr.end(), [&](int a, int b) -> bool {
            return cal(value, mat, a) < cal(value, mat, b) ||
                (cal(value, mat, a) == cal(value, mat, b) && a < b);  
        }); 
        return vector<int>(subarr.begin(), subarr.begin() + k); 
    }
};