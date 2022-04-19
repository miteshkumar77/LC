// https://leetcode.com/problems/maximum-number-of-eaten-apples

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
      
        int n = apples.size();
        
        map<int, int> ct;
        int latest = n;
        int ans = 0;
        for (int d = 0; d < latest; ++d) {
            if (d < n && apples[d] != 0) {
                ct[days[d] + d] += apples[d];
                latest = max(days[d] + d, latest);
            }
            
            while(ct.size() != 0 && ct.begin() -> first <= d) {
                ct.erase(ct.begin());
            }
            
            if (ct.size() != 0) {
                ++ans;
                --ct[ct.begin() -> first];
                if (ct.begin() -> second == 0) {
                    ct.erase(ct.begin());
                }
            }
        }
        
        
        
        return ans;
    }
};