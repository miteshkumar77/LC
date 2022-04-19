// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> pos;
        int ans = 0;
        int earliest = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (pos.find(s[i]) != pos.end()) {
                earliest = max(earliest, pos[s[i]]); 
            }
            pos[s[i]] = i;
            ans = max(ans, i - earliest);
        }
        return ans;
    }
};