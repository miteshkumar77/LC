// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        auto r = countAndSay(n-1);
        string res;
        int ct = 1;
        for (int i = 1; i <= r.length(); ++i) {
            if (i < r.length() && r[i] == r[i-1]) ++ct;
            else { res = res + to_string(ct) + to_string(r[i-1]-'0'); ct = 1; }
        }
        return res;
    }
};