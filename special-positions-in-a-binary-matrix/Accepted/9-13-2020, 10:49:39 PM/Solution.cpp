// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        if (mat.size() == 0 || mat[0].size() == 0) {
            return 0; 
        }
        vector<int> rows(mat.size(), 0); 
        vector<int> cols(mat[0].size(), 0); 
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 1) {
                    ++rows[i];
                    ++cols[j]; 
                }
            }
        }
        // for (int i : rows) cout << i << ' ';
        // cout << endl; 
        // for (int i : cols) cout << i << ' ';
        // cout << endl; 
        int ans = 0; 
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (rows[i] == 1 && cols[j] == 1 && mat[i][j] == 1) {
                    ++ans; 
                }
            }
        }
        return ans; 
    }
};