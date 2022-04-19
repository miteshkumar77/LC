// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> ses;
        ses.reserve(intervals.size() * 2); 
        for (int i = 0; i < intervals.size(); ++i) {
            ses.push_back(make_pair(intervals[i][0], 1)); 
            ses.push_back(make_pair(intervals[i][1], -1)); 
        }
        
        sort(ses.begin(), ses.end()); 
        
        int depth = 0; 
        int ans = 0; 
        for (auto i : ses) {
            depth += i.second;  
            ans = max(ans, depth); 
        }
        return ans; 
    }
};