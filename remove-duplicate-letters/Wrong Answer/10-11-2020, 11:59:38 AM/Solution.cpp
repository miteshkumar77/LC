// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> ct(26, 0);
        for (char c : s) ++ct[c - 'a'];
        string ans = "";
        
        unordered_set<char> seen;
        
        for (char c : s) {
            --ct[c - 'a'];
            if (seen.find(c) != seen.end()) continue;
            
            while(!ans.empty() && c < ans.back() && ct[ans.back() - 'a'] > 0) {
                ans.pop_back();
            }
            ans += c;
        }
        return ans;
    }
};