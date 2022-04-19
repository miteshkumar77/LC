// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> ct; 
        int j = 0; 
        int ans = 0; 
        int windowsize = 0; 
        for (int i = 0; i < s.length(); ++i) {
            while(j < s.length() && ct.size() <= k) {
                ans = max(ans, windowsize); 
                ++ct[s[j++]]; 
                ++windowsize; 
            }
            if (ct.size() <= k) {
                ans = max(ans, windowsize); 
            }
            --ct[s[i]]; 
            if (ct[s[i]] == 0) {
                ct.erase(s[i]); 
            }
            --windowsize; 
        }
        return ans; 
    }
};