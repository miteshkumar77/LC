// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        vector<array<int, 4>> groups; 
        /**
            g[0] = num_adj
            g[1] = char - 'a'
            g[2] = max cost
            g[3] = total cost
        
        **/
        for (int i = 0; i < s.length(); ++i) {
            if (groups.size() == 0 || groups.back()[1] != (s[i] - 'a')) {
                groups.push_back(array<int, 4>{0, s[i] - 'a', 0, 0}); 
            }
            ++groups.back()[0];
            groups.back()[2] = max(groups.back()[2], cost[i]); 
            groups.back()[3] += cost[i]; 
        }
        int ans = 0; 
        for (auto a : groups) {
            ans += a[3] - a[2]; 
        }
        return ans; 
    }
};