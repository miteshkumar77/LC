// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    vector<array<int, 2>> pts;
    int ans;
    int n;
    
    void solve() {
        if (pts.size() == n) {
            ++ans;
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
    
    int totalNQueens(int n) {
        this->n = n;
        this->ans = 0;
        solve();
        return ans;
    }
};