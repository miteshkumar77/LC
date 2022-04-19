// https://leetcode.com/problems/add-minimum-number-of-rungs

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int h = 0;
        int n = rungs.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (rungs[i] - h > dist) {
                ans += (rungs[i] - 1 - h)/dist;
            }
            h = rungs[i];
        }
        return ans;
    }
};