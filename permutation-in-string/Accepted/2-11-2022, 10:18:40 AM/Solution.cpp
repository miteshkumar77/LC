// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n10 = n1;
        int n2 = s2.length();
        array<int, 26> ct{};
        for (char c : s1)
            ++ct[c-'a'];
        
        int j = 0;
        for (int i = 0; i < n2; ++i) {
            if (--ct[s2[i]-'a'] >= 0) {
                --n1;
            }
            while(j <= i && n1 == 0) {
                if (i - j + 1 == n10) {
                    return true;
                }
                if (++ct[s2[j++]-'a'] > 0) {
                    ++n1;
                }
            }
        }
        
        return false;
    }
};