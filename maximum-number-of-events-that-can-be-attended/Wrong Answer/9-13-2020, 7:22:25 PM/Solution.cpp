// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0];     
        });
        
        
        vector<int> pre = events[0]; 
        
        int ans = 0; 
        
        for (int i = 0; i < events.size(); ++i) {
            if (events[i][0] <= pre[1]) {
                pre[1] = max(pre[1], events[i][1]); 
            } else {
                ans += pre[1] - pre[0] + 1; 
                pre = events[i]; 
            }
        }
        ans += pre[1] - pre[0] + 1; 
        return min(ans, (signed int)events.size()); 
    }
};