// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int j = 0;
        array<int, 3> ct;
        fill(ct.begin(), ct.end(), 0);
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ++ct[s[i] - 'a'];
            while(ct[0] && ct[1] && ct[2]) {
                ans += (n - i); 
                --ct[s[j++] - 'a'];
            }
        }
        
        return ans;
    }
};