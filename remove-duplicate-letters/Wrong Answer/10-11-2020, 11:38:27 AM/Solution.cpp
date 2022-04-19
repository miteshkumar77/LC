// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> ct(26, 0);
        
        for (char c : s) {
            ++ct[c - 'a'];
        }
        
        list<char> stk;
        for (char c : s) {
            while((!stk.size() == 0) && c < stk.back() && ct[stk.back() - 'a'] > 0) {
                stk.pop_back();
            }
            stk.push_back(c);
            --ct[c - 'a'];
        }
        
        string ans;
        unordered_set<char> seen;
        for (char c : stk) {
            if (seen.find(c) == seen.end()) {
                seen.insert(c);
                ans += c;
            }
        }
        return ans;
    }
};