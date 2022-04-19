// https://leetcode.com/problems/range-addition-ii

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int N = ops.size();
        for (int i = 0; i < N; ++i) {
            m = min(ops[i][0], m);
            n = min(ops[i][1], n);
        }
        return m * n;
    }
};