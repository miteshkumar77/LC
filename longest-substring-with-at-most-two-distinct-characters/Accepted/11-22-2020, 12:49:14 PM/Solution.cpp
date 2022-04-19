// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        array<int, 256> ct;
        fill(ct.begin(), ct.end(), 0);
        int unique = 0;
        int j = -1;
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (ct[s[i]] == 0) ++unique;
            ++ct[s[i]];
            
            while(j < i && unique > 2) {
                --ct[s[++j]]; 
                if (ct[s[j]] == 0) --unique;
            }
            
            ans = max(ans, i - j);
            
        }
        return ans;
    }
};
/**
    e c e b a
    1 2 3 2 2 
    0 1 2 3 4
    e:  2
    c:  1
    b:  3
    a:  4

*/




