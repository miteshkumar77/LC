// https://leetcode.com/problems/meeting-rooms

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0]; 
        }); 
        for (int i = 0; i < (signed int)intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false; 
            }
        }
        return true; 
    }
};