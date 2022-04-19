// https://leetcode.com/problems/get-equal-substrings-within-budget

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int j = 0; 
        int cost = 0; 
        int ans = 0; 
        for (int i = 0; i < t.size(); ++i) {
            cost += abs(s[i] - t[i]); 
            while(j <= i && cost > maxCost) {
                cost -= abs(s[j] - t[j]); 
                ++j; 
            }
            ans = max(ans, i - j + 1); 
        }
        return ans; 
    }
};