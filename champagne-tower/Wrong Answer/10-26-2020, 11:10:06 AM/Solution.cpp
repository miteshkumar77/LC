// https://leetcode.com/problems/champagne-tower

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(101, vector<double>(101));
        
        // function<void()> pour = [&]() -> void {
        //     glasses[0] += poured;
        //     for (int i = 0; i < )
        // }
        
        glasses[0][0] += (double)(poured);
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j <= i; ++j) {
                
                double excess = max(0.0, (glasses[i][j] - 1)/2);
                
                glasses[i + 1][j] += excess;
                glasses[i + 1][j + 1] += excess;
            }
        }
        
        return glasses[query_row][query_glass];
    }
};