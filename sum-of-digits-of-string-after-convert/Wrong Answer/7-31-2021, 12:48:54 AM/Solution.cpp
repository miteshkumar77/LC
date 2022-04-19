// https://leetcode.com/problems/sum-of-digits-of-string-after-convert

class Solution {
public:
    
    int getLucky(string s, int k) {
        string t = "";
        for (char c : s) t += to_string((int)(c-'a'+1));
        int a = 0;
        for (int i = 0; i < t.length(); ++i) {
            a += t[i] - '0';
        }
        if (k == 1) return a;
        return getLucky(to_string(a), k-1);
    }
};