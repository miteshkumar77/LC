// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.reserve(numRows);
        ans.push_back({1});
        for (int i = 1; i < numRows; ++i) {
            ans.emplace_back();
            ans.back().reserve(i+1);
            for (int j = 0; j <= i; ++j) {
                ans.back().emplace_back(j == 0 || j == i ? 1 : ans[i-1][j] + ans[i-1][j-1]);
            }
        }
        return ans;
    }
};