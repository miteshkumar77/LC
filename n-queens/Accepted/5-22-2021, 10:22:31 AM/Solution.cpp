// https://leetcode.com/problems/n-queens

class Solution {
public:
    vector<array<int, 2>> pts;
    vector<vector<string>> ans;
    int n;
    
    void solve() {
        if (pts.size() == n) {
            ans.push_back(vector<string>(n, string(n, '.')));
            for (const auto& p : pts) {
                ans.back()[p[0]][p[1]] = 'Q';
            }
        } else {
            int i = pts.size();
            for (int j = 0; j < n; ++j) {
                bool good = true;
                for (const auto& p : pts) {
                    if ((p[0] - i) == (p[1] - j) || (p[0] - i) == (j - p[1]) || p[1] == j) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    pts.push_back({i,j});
                    solve();
                    pts.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        solve();
        return ans;
    }
};