// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_set<char> chars;
        for (char c : s) {
            chars.insert(c);
        }
        
        int numUnique = chars.size();
        
        function<bool(unordered_map<char,int>&)> checkK = [&](unordered_map<char, int>& ct) -> bool {
            int len = 0;
            for (auto p : ct) {
                len += p.second;
                // cout << p.first << ": " << p.second << endl;
                if (p.second < k) return false;
            }
            // cout << len << endl;
            return true;
        }; 
        
        int ans = 0;
        
        for (int u = 1; u <= numUnique; ++u) {
            int j = 0; 
            unordered_map<char, int> ct;
            for (int i = 0; i < s.length(); ++i) {
                ++ct[s[i]];
                while(j <= i && ct.size() > u) {
                    --ct[s[i]];
                    if (ct[s[i]] == 0) ct.erase(s[i]);
                    ++j;
                }
                if (j <= i && checkK(ct)) {
                    // cout << i << ' ' << j << endl;
                    ans = max(ans, i - j + 1);
                }
            }
        }
        
        return ans;
    }
};