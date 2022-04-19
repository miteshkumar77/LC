// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<int,int> ct;
        int j = 0;
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++ct[s[i] - '0'];
            
            while(j <= i && ct.size() > k) {
                --ct[s[j] - '0'];
                if (ct[s[j]] == 0) {
                    ct.erase(s[j]);
                }
                ++j;
            }
            
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};