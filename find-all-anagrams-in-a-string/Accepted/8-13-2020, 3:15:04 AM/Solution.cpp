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
        
        
        function<int(char)> getdif = [&] (char c) -> int {
            return abs(ctr[c - 'a'] - cmp[c - 'a']);     
        };
        
        vector<int> ans; 
        int dif = p.length(); 
        
        for (int i = 0; i < p.length(); ++i) {
            int pre = getdif(s[i]); 
            ++ctr[s[i] - 'a']; 
            int post = getdif(s[i]); 
            dif += post - pre; 
        }
        
        if (dif == 0) {
            ans.push_back(0); 
        }
        
        for (int i = p.length(); i < s.length(); ++i) {
            int pre = getdif(s[i]) + getdif(s[i - p.length()]); 
            ++ctr[s[i] - 'a'];
            --ctr[s[i - p.length()] - 'a']; 
            int post = getdif(s[i]) + getdif(s[i - p.length()]); 
            dif += post - pre; 
            
            if (dif == 0) {
                ans.push_back(i - p.length() + 1); 
            }
        }
        
        
        return ans; 
        
        
    }
};