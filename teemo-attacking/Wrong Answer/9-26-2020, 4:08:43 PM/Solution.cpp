// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int d) {
        sort(timeSeries.begin(), timeSeries.end()); 
        
        int duration = 0; 
        int maxTime = 0; 
        for (int i = 0; i < timeSeries.size(); ++i) {
            if (maxTime > timeSeries[i]) {
                duration = maxTime - timeSeries[i] + d;
            } else {
                duration += d; 
            }
            maxTime = timeSeries[i] + d; 
        }
        
        return duration; 
    }
};