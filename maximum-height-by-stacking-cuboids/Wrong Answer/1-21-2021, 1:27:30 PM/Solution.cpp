// https://leetcode.com/problems/maximum-height-by-stacking-cuboids

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto& v : cuboids) {
            sort(v.begin(), v.end());
        }
        
        sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            for (int i = 2; i >= 0; --i) {
                if (a[i] > b[i]) {
                    return true;
                } else if (a[0] < b[0]) {
                    return false;
                }
            }
            return true;
        }); 
        
        for (auto v : cuboids) {
            cout << "[" << v[0] << "," << v[1] << "," << v[2] << "]" << ",";    
        }cout << endl;
        
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(3, 0));
        for (int i = 0; i < n; ++i) {
            auto ci = cuboids[i];
            for (int hi = 0; hi < 3; ++hi) {
                dp[i][hi] = ci[hi];
                ans = max(ans, dp[i][hi]);
            }
            for (int j = 0; j < i; ++j) {
                auto cj = cuboids[j];
                
                for (int hi = 0; hi < 3; ++hi) {
                    for (int hj = 0; hj < 3; ++hj) {
                        
                        if (ci[hi] <= cj[hj]) {
                            if (min(ci[(hi + 1) % 3], ci[(hi + 2) % 3]) <= min(cj[(hj + 1) % 3], cj[(hj + 2) % 3]) &&
                                max(ci[(hi + 1) % 3], ci[(hi + 2) % 3]) <= max(cj[(hj + 1) % 3], cj[(hj + 2) % 3])) {
                                dp[i][hi] = max(dp[i][hi], dp[j][hj] + ci[hi]); 
                                ans = max(ans, dp[i][hi]);
                            }
                        }
                    }
                }
            }
        }
        
        for (auto v : dp) {
            cout << "[" << v[0] << "," << v[1] << "," << v[2] << "]" << ",";    
        }cout << endl;
        
        return ans;

    }
};