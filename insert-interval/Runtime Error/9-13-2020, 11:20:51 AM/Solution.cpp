// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            if ((*it)[0] >= newInterval[0]) {
                intervals.insert(it, newInterval); 
                break;
            }
            if (next(it) == intervals.end()) {
                intervals.push_back(newInterval); 
            }
        }
        
        if (intervals.size() == 0) {
            intervals.push_back(newInterval); 
        }

        vector<vector<int>> ans{intervals[0]}; 
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]); 
            } else {
                ans.push_back(intervals[i]); 
            }
        }
        return ans; 
        
    }
};