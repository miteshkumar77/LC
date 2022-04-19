// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        vector<pair<int,char>> stk;
        for (char c : s) {
            if (stk.size() == 0) {
                stk.push_back({0, c});
            }
            if (stk.back().second != c && stk.back().first > 1) {
                stk.pop_back();
            }
            if (stk.size() == 0 || stk.back().second != c) {
                stk.push_back({0, c});
            }
            ++stk.back().first;
        }
        if (stk.back().first > 1) {
            stk.pop_back();
        }
        string ans = "";
        for (const auto& p : stk) {
            ans += string(p.first, p.second);
        }
        return ans;
    }
};