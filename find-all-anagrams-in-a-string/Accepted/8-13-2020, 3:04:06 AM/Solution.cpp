// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.length() == 0) {
            return vector<int>(); 
        }
        if (s.length() < p.length()) {
            return vector<int>(); 
        }
        array<int, 26> ctr; 
        array<int, 26> cmp; 
        fill(ctr.begin(), ctr.end(), 0); 
        fill(cmp.begin(), cmp.end(), 0); 
        
        for (char c : p) {
            ++cmp[c - 'a'];
        }
        
        
        
        function<bool()> chk = [&]() -> bool {
            for (int i = 0; i < 26; ++i) {
                if (ctr[i] != cmp[i]) {
                    return false; 
                }
            }
            
            return true; 
        };
        
        vector<int> ans; 
        // int num_mismatch = 0; 
        
        for (int i = 0; i < p.length(); ++i) {
            ++ctr[s[i] - 'a']; 
        }
        
        if (chk()) {
            ans.push_back(0); 
        }
        
        
        for (int i = p.length(); i < s.length(); ++i) {
            --ctr[s[i - p.length()] - 'a'];
            ++ctr[s[i] - 'a']; 
            if (chk()) {
                ans.push_back(i - p.length() + 1); 
            }
        }
        
        
        return ans; 
        
        
    }
};