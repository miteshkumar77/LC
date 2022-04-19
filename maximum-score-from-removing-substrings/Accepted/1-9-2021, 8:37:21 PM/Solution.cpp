// https://leetcode.com/problems/maximum-score-from-removing-substrings

class Solution {
public:
    
    pair<string, int> eval(const string& s, string p, int val) {
        string stk;
        int ans = 0;
        for (char c : s) {
            stk.push_back(c);
            while(true) {
                if (stk.size() >= 2 && stk.substr(stk.size() - 2, 2) == p) {
                    ans += val;
                    stk.pop_back();
                    stk.pop_back();
                } else {
                    break;
                }
            }
        }
        // cout << s << ' ' << ans << endl;
        return {stk, ans};
    }
    
    int maximumGain(string s, int x, int y) {
        auto p1 = eval(s, "ab", x);
        auto p2 = eval(s, "ba", y);
        // cout << p1.first << ' ' << p2.first << endl;
        return max(p1.second + eval(p1.first, "ba", y).second,
                   p2.second + eval(p2.first, "ab", x).second);
    }
};