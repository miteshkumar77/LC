// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        ans.reserve(intervals.size()); 
        ans.push_back(intervals[0]); 
        bool added = false; 
        for (int i = 1; i < intervals.size(); ++i) {
            if (!added && newInterval[0] <= ans.back()[1]) {
                added = true; 
                if (newInterval[1] <= ans.back()[1]) {
                    return intervals; 
                }
                
                ans.back()[1] = newInterval[1];
            }
            
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            } else {
                ans.push_back(intervals[i]); 
            }
        }
        
        if (!added) {
            ans.push_back(newInterval); 
        }
        return ans; 
        
    }
};