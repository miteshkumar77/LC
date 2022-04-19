// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&] (const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] < b[1]; 
        }); 
        
        int mindist = intervals[0][0]; 
        int size = 0; 
        for (int i = 0; i < intervals.size(); ++i) {
            // cout << mindist << endl; 
            if (intervals[i][0] >= mindist) {
                mindist = intervals[i][1];
                // cout << intervals[i][0] << ' ' << intervals[i][1] << endl; 
                
                ++size; 
            }
        }
        return intervals.size() - size; 
    }
};