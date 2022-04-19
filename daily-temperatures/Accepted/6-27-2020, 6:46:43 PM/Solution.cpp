// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> hist(101, -1); 
        vector<int> ans(T.size(), 0); 
        for (int i = T.size() - 1; i >= 0; --i) {
            int earliest = INT_MAX; 
            
            for (int x = T[i] + 1; x <= 100; ++x) {
                if (hist[x] != -1) {
                    earliest = min(earliest, hist[x]); 
                }
            }
            
            if (earliest != INT_MAX) {
                ans[i] = earliest - i; 
            }
            hist[T[i]] = i; 
        }
        return ans; 
    }
};