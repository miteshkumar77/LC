// https://leetcode.com/problems/champagne-tower

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(101, vector<double>(101, 0.0));
        glasses[0][0] = poured;
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j <= i; ++j) {
                double excess = max(0.0, (glasses[i][j] - 1.0)/2);
                glasses[i][j] = min(1.0 , glasses[i][j]);
                if (i == query_row && j == query_glass) {
                    return glasses[i][j];
                }
                glasses[i + 1][j] += excess;
                glasses[i + 1][j + 1] += excess;
            }
        }
        return glasses[query_row][query_glass];
    }
};