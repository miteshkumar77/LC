// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> pref (s.length(), 0); 
        if (isVowel(s[0])) {
            pref[0] = 1; 
        }
        
        for (int i = 1; i < s.length(); ++i) {
            pref[i] = pref[i - 1]; 
            if (isVowel(s[i])) {
                pref[i] += 1; 
            }
        }
        
        int ans = pref[k - 1]; 
        for (int i = k; i < s.length(); ++i) {
            ans = max(pref[i] - pref[i - k], ans); 
        }
        return ans; 
    }
    
    
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); 
    }
};