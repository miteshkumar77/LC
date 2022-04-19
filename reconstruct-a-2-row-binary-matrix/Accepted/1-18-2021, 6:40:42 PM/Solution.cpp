// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(n, vector<int>(2, 0)); 
        int curr_upper = 0;
        int curr_lower = 0;
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 1) {
                ++curr_upper;
                ans[i][0] = 1;
            } else if (colsum[i] == 2) {
                ++curr_upper;
                ++curr_lower;
                ans[i][0] = 1;
                ans[i][1] = 1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (ans[i][0] == 1 && ans[i][1] == 0 && curr_upper > upper && curr_lower < lower) {
                swap(ans[i][0], ans[i][1]);
                ++curr_lower;
                --curr_upper;
            }
        }
        
        if (curr_upper != upper || curr_lower != lower) {
            return vector<vector<int>>();
        }
        
        vector<vector<int>> ret(2, vector<int>(n, 0)); 
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                ret[i][j] = ans[j][i];
            }
        }
        return ret;
    }
};