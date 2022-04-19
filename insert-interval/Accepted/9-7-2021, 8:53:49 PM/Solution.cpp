// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int l = 0; int r = n-1;
        int ans = n;
        int mid;
        while(l <= r) {
            mid = r;
            if (intervals[mid][0] >= newInterval[0]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        intervals.insert(intervals.begin() + ans, newInterval);
        vector<vector<int>> ret; ret.reserve(n);
        for (int i = 0; i <= n; ++i) {
            if (ret.empty() || ret.back()[1] < intervals[i][0]) {
                ret.push_back(intervals[i]);
            } else {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }
        }
        return ret;
    }
};