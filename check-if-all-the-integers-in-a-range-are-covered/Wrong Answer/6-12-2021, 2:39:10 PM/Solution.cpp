// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int mi = INT_MAX;
        int ma = INT_MIN;
        for (const auto& r : ranges) {
            mi = min(mi, r[0]);
            ma = max(ma, r[1]);
        }
        return mi <= left && ma >= right;
    }
};