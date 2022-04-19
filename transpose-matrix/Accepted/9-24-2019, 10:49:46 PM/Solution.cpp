// https://leetcode.com/problems/transpose-matrix

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int c = 0;
        int t = A.size() - 1;
        vector<vector<int>> ret;
        vector<int> empt;
        ret.push_back(empt);
        for (int i = 0; i < A[0].size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                if (ret.back().size() == A.size()) {
                    ret.push_back(empt);
                }
                
                ret.back().push_back(A[j][i]);
            }
        }
        
        return ret;
    }
};