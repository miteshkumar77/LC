// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
        });
        
        // [1,4],[3,6][2,8]
        // [1,4],[2,8],[3,6]
        
        int m_end = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if (m_end < intervals[i][1]) {
                m_end = intervals[i][1];
                ++ans;
            }
        }
        return ans;
    }
};