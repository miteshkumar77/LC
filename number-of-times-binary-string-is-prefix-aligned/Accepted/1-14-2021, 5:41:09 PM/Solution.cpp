// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        unordered_set<int> seen;
        int latest = 0;
        int highestSeen = 0;
        int ans = 0;
        for (int i = 0; i < light.size(); ++i) {
            seen.insert(light[i]);
            highestSeen = max(light[i], highestSeen);
            while(latest < highestSeen && seen.count(latest + 1)) latest = latest + 1;
            ans += (highestSeen == latest);
        }
        return ans;
        
    }
};