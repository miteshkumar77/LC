// https://leetcode.com/problems/minimum-space-wasted-from-packaging

class Solution {
public:
    int cost(vector<int>& packages, vector<int>& boxes) {
        sort(boxes.begin(), boxes.end());
        int j = 0;
        int ans = 0;
        for (int i : packages) {
            while(j < boxes.size() && boxes[j] < i) ++j;
            if (j >= boxes.size()) return INT_MAX;
            ans += boxes[j] - i;
        }
        return ans;
    }
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        int ans = INT_MAX;
        for (auto& v : boxes) {
            ans = min(ans, cost(packages, v));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};