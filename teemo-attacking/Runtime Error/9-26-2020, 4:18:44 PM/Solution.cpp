// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int d) {
        sort(timeSeries.begin(), timeSeries.end()); 
        
        int maxInterval = timeSeries[0] + d - 1; 
        int prevStart = timeSeries[0]; 
        int duration = 0; 
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (maxInterval >= timeSeries[i]) {
                maxInterval = timeSeries[i] + d - 1; 
            } else {
                // cout << prevStart << ' ' << maxInterval << endl; 
                duration += maxInterval - prevStart + 1; 
                prevStart = timeSeries[i];
                maxInterval = prevStart + d - 1; 
            }
        }
        // cout << prevStart << ' ' << maxInterval << endl; 
        duration += maxInterval - prevStart + 1; 
        
        
        return duration; 
    }
};