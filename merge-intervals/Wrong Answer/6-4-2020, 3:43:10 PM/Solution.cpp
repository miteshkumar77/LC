// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if (intervals.size() <= 1) {
            return intervals; 
        }
        sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] < b[0]; 
        }); 
        vector<vector<int> > ans; 
        int start = intervals[0][0]; 
        int end = intervals[0][1]; 
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i - 1][1] >= intervals[i][0]) {
                end = max(end, intervals[i][1]); 
            } else {
                ans.push_back(vector<int>{start, end}); 
                start = intervals[i][0]; 
                end = intervals[i][1]; 
            }
        }
        
        if (ans.size() == 0 || end > ans[ans.size() - 1][1]) {
            ans.push_back(vector<int>{start, end}); 
        }
        return ans; 
    }
};