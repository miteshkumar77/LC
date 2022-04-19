// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int d) {
        sort(timeSeries.begin(), timeSeries.end()); 
        
        int maxInterval = 0; 
        int prevStart = 0; 
        int duration = 0; 
        for (int i = 0; i < timeSeries.size(); ++i) {
            if (maxInterval >= timeSeries[i]) {
                maxInterval = timeSeries[i] + d; 
            } else {
                duration += maxInterval - prevStart - 1; 
                prevStart = timeSeries[i];
                maxInterval = prevStart + d; 
            }
        }
        // cout << prevStart << ' ' << maxInterval << endl; 
        duration += maxInterval - prevStart + 1; 
        
        
        return duration; 
    }
};