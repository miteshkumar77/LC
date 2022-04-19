// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] < b[1];
        });
        
        
        int selected = intervals.size();
        int mind = INT_MIN;
        for (const auto& v : intervals) {
            if (v[0] >= mind) {
                --selected;
                mind = v[1];
            }
        }
        return selected;
    }
};