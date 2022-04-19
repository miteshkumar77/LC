// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [] (vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]); 
        }); 
        
        // for (auto v : events) cout << v[0] << ' ' << v[1] << ", "; 
        // cout << endl; 
        int min_day = -1;
        int ans = 0; 
        for (int i = 0; i < events.size(); ++i) {
            if (min_day < events[i][1]) {
                ++ans; 
                min_day = max(min_day + 1, events[i][0]); 
            }
        }
        return ans; 
    }
};