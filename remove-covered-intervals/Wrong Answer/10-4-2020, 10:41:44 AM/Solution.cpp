// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1];    
        });
        // [3,10], [4,10], [5,11]
        
        int m_start = intervals[0][0];
        int m_end   = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if (m_start <= intervals[i][0] && m_end >= intervals[i][1]) {
                continue;
            } else if (m_start >= intervals[i][0] && m_end <= intervals[i][1]) {
                m_start = intervals[i][0];
                m_end = intervals[i][1];
                continue;
            }
            m_start = intervals[i][0];
            m_end = intervals[i][1];
            ++ans;
        }
        return ans;
        // [[1,4],[3,6],[2,8]]
        // 
    }
};