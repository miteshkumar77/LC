// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            return vector<vector<int> >{newInterval};
        }
        vector<vector<int> > ans;
        ans.reserve(intervals.size()); 
        bool added = false; 
        for (int i = 0; i <= intervals.size(); ++i) {
            vector<int> nextInterval; 
            
            if (i == intervals.size()) {
                if (added) {
                    break; 
                }
                
                nextInterval = newInterval; 
                added = true; 
            } else {
                if (!added && newInterval[0] <= intervals[i][0]) {
                    nextInterval = newInterval;
                    --i; 
                    added = true; 
                } else {
                    nextInterval = intervals[i]; 
                }
            }
            
            if (ans.size() == 0) {
                ans.push_back(nextInterval);
            } else {
                if (ans.back()[1] >= nextInterval[0]) {
                    ans.back()[1] = max(ans.back()[1], nextInterval[1]); 
                } else {
                    ans.push_back(nextInterval);
                }
            }
        }
        return ans; 
        
    }
};