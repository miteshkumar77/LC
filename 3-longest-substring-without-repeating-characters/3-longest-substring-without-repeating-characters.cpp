class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> pos;
        int e = -1;
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (pos.count(s[i])) {
                e = max(pos[s[i]], e);
            }
            ans = max(ans, i - e);
            pos[s[i]] = i;
        }
        return ans;
    }
};