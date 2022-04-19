// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings

class Solution {
public:
    int maxUniqueSplit(string s) {
        int ans = 0;
        unordered_set<string> occs;
        function<void(int)> bt = [&](int i) -> void {
            if (i == s.length()) {
                ans = max(ans, (int)occs.size()); 
            }
            
            for (int j = i; j < s.length(); ++j) {
                string tmp = s.substr(i, j - i + 1); 
                if (occs.find(tmp) == occs.end()) {
                    occs.insert(tmp); 
                    bt(j + 1); 
                    occs.erase(tmp); 
                }
            }
        };
        
        bt(0); 
        return ans; 
    }
};