// https://leetcode.com/problems/substring-with-concatenation-of-all-words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        function<bool(int)> check = [&](int i) -> bool {
            unordered_map<string, int> ct;
            for (auto word : words) ++ct[word];
            string buf;
            for (int x = i; x < s.length(); ++x) {
                buf += s[x];
                if (buf.length() == words[0].length()) {
                    if (ct.find(buf) != ct.end()) {
                        --ct[buf];
                        if (ct[buf] == 0) {
                            ct.erase(buf);
                        }
                        
                    } else {
                        return false;
                    }
                    
                    if (ct.size() == 0) {
                        return true;
                        
                    }
                    buf = "";
                }
            }
            return false;
        };
        vector<int> ans;
        int l = words.size() * words[0].length();
        for (int i = 0; i + l <= s.length(); ++i) {
            if (check(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};