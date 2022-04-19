// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] - a[0] < b[1] - b[0];  
        });
        
//         int m_start = intervals[0][0];
//         int m_end   = intervals[0][1];
//         int ans = 1;
//         for (int i = 1; i < intervals.size(); ++i) {
//             if (m_start <= intervals[i][0] && m_end >= intervals[i][1]) {
//                 continue;
//             } else if (m_start >= intervals[i][0] && m_end <= intervals[i][1]) {
//                 m_start = intervals[i][0];
//                 m_end = intervals[i][1];
//                 continue;
//             }
//             m_start = intervals[i][0];
//             m_end = intervals[i][1];
//             ++ans;
//         }
//         return ans;
        
        function<bool(vector<int>&,vector<int>&)> isCovered = [&](vector<int>& a, vector<int>& b) -> bool {
            return a[0] >= b[0] && a[1] <= b[1];    
        };
        
        int ans = intervals.size();
        for (int i = 0; i < intervals.size(); ++i) {
            for (int j = i + 1; j < intervals.size(); ++j) {
                if (isCovered(intervals[i], intervals[j])) {
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};