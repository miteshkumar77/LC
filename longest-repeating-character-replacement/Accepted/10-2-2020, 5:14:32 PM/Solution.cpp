// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> ct(26, 0);
        
        function<int()> getmax = [&]() -> int {
            int m = ct[0];
            for (int i : ct) {
                m = max(m, i);
            }
            return m;
        };
        
        int j = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++ct[s[i] - 'A'];
            while(j <= i && (i - j + 1) - getmax() > k) {
                --ct[s[j++] - 'A'];
            }
            if (j <= i) {
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
        
        
        
    }
        
};