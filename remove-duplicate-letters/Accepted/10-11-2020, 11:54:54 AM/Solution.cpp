// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> ct(26, 0);
        
        for (char c : s) {
            ++ct[c - 'a'];
        }
        
        list<char> stk;
        unordered_set<char> seen;

        for (char c : s) {
            
            if (seen.find(c) != seen.end()) {
                --ct[c - 'a'];
                continue;
            }
            
            while((!(stk.size() == 0)) && c < stk.back() && ct[stk.back() - 'a'] > 0) {
                seen.erase(stk.back());
                stk.pop_back();
                
            }
            seen.insert(c);
            stk.push_back(c);
            --ct[c - 'a'];
        }
        
        seen.clear();
        string ans;
        for (char c : stk) {
            if (seen.find(c) != seen.end()) continue;
            seen.insert(c);
            ans += c;
            
        }
        return ans;
    }
};