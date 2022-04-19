// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0 || duration == 0) {
            return 0; 
        }
        int ans = 0; 
        int start = timeSeries[0]; 
        int max_interval = timeSeries[0] + duration; 
        
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (max_interval >= timeSeries[i]) {
                max_interval = max(timeSeries[i] + duration, max_interval); 
            } else {
                ans += max_interval - start; 
                start = timeSeries[i]; 
                max_interval = start + duration; 
            }
        }
        ans += max_interval - start; 
        return ans; 
    }
};