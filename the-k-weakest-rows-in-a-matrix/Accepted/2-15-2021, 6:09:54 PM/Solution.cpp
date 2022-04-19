// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
    int cal(vector<int>& value, vector<vector<int>>& mat, int r) {
        if (value[r] == -1) {
            value[r] = accumulate(mat[r].begin(), mat[r].end(), 0); 
        }
        return value[r]; 
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