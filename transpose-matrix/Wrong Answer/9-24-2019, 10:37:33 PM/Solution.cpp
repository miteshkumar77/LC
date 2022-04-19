// https://leetcode.com/problems/transpose-matrix

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int t = A.size();
        vector<vector<int>> ret;
        vector<int> empt;
        int c = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (c % t == 0) {
                    ret.push_back(empt);
                }
                ret.back().push_back(A[i][j]);
                c++;
            }
        }
        
        c = 0;
        vector<vector<int>> ret2;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (c % t == 0) {
                    ret2.push_back(empt);
                }
                ret2.back().push_back(ret[j][i]);
                c++;
            }
        }
        
        return ret;
    }
};