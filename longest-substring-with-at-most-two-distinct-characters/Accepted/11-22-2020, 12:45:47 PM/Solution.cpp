// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        array<int, 256> ct;
        fill(ct.begin(), ct.end(), -1);
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ct[s[i]] = i;
            int min1 = -1;
            int min2 = -1;
            
            for (int j = 0; j < 256; ++j) {
                if (j != s[i]) {
                    if (ct[j] > min1) {
                        min2 = min1;
                        min1 = ct[j];
                    } else if (ct[j] > min2) {
                        min2 = ct[j];
                    }
                }
            }
            // cout << min2 << ' ';
            ans = max(ans, i - min2);
            
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




