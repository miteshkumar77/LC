// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 1) {
                if (upper > lower) {
                    --upper;
                    ans[0][i] = 1;
                } else {
                    --lower;
                    ans[1][i] = 1;
                }
            
            } else if (colsum[i] == 2) {
                --upper;
                --lower;
                ans[0][i] = 1;
                ans[1][i] = 1;
            }
        }
        
        if (upper == 0 && lower == 0) return ans;
        return vector<vector<int>>();
    }
};