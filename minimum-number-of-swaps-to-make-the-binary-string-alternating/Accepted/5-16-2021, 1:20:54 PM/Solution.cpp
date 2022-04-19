// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating

class Solution {
public:
    int swaps(const string& a, const string& b) {
        int n = a.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (a[i] != b[i]);
        }
        return ans / 2;
    }
    
    int minSwaps(string s) {
        int ones = 0;
        int zeros = 0;
        for (char c : s) {
            ones += (c == '1');
            zeros += (c == '0');
        }
        int ans = INT_MAX;
        int o = ones;
        int z = zeros;
        string s1;
        while(o && z) {
            --o;
            --z;
            s1 += "01";
        }
        if ((z == 0 && o == 0) || (z == 1 && o == 0)) {
            if (z) {
                --z;
                s1 += "0";
            }
            ans = min(ans, swaps(s, s1));
        }
        s1 = "";
        o = ones; z = zeros;
        while(o && z) {
            --o;
            --z;
            s1 += "10";
        }
        if ((z == 0 && o == 0) || (z == 0 && o == 1)) {
            if (o) {
                --o;
                s1 += "1";
            }
            ans = min(ans, swaps(s, s1));
        }
        return ans == INT_MAX ? -1 : ans;
        
    }
};