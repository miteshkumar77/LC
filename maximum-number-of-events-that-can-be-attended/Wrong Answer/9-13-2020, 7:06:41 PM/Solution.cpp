// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [] (vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0]; 
        }); 
        int min_day = -1;
        int ans = 0; 
        for (int i = 0; i < events.size(); ++i) {
            if (events[i][0] > min_day || min_day < events[i][1]) {
                ++ans; 
                min_day = max(min_day + 1, events[i][0]); 
            }
        }
        return ans; 
    }
};