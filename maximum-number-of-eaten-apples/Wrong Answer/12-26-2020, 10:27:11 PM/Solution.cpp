// https://leetcode.com/problems/maximum-number-of-eaten-apples

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        map<int, int> ct;
        int latest_day = n;
        int ans = 0;
        for (int i = 0; i < latest_day; ++i) {
            
            
            if (apples[i] != 0) {
                ct[i + days[i]] += apples[i];
                latest_day = max(latest_day, i + days[i]);
            }
            
            while(ct.size() > 0 && ct.begin() -> first < i) {
                ct.erase(ct.begin());
            }
            
            if (ct.size() > 0 && ct.begin() -> first > i) {
                --ct.begin() -> second;
                if (ct.begin() -> second == 0) {
                    ct.erase(ct.begin());
                }
                ++ans;
            }
        }
        
        
        
        return ans;
    }
};