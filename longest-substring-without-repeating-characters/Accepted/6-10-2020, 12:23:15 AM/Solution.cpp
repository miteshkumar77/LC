// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen; 
        int lower_bound = 0; 
        int max_len = 0; 
        for (int i = 0; i < s.length(); ++i) {
            auto it = last_seen.find(s[i]); 
            if (it == last_seen.end()) {
                last_seen[s[i]] = i; 
            } else {
                if (it -> second >= lower_bound) {
                    lower_bound = it -> second + 1; 
                }
                it -> second = i; 
            }
            max_len = max(i - lower_bound + 1, max_len); 
        }
        return max_len; 
    }
};