// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> ct;
        fill(ct.begin(), ct.end(), 0);
        for (char c : s) {
            ++ct[c - 'a'];
        }
        vector<bool> used(26, false);
        string ans;
        for (char c : s) {
            --ct[c - 'a'];
            if (!used[c - 'a']) {
                while(!ans.empty() && c < ans.back() && 
                     ct[ans.back() - 'a'] > 0) {
                    used[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                ans.push_back(c);
                used[c - 'a'] = true;
            }
        }
        return ans;
    }
};