// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> ct1(26, 0);
        vector<int> ct2(26, 0);
        for (char c : word1) ++ct1[c - 'a'];
        for (char c : word2) ++ct2[c - 'a'];
        
        for (int i = 0; i < 26; ++i) {
            if ((ct1[i] == 0 && ct2[i] != 0) || (ct1[i] != 0 && ct2[i] == 0)) {
                return false;
            }
        }
        sort(ct1.begin(), ct1.end()); 
        sort(ct2.begin(), ct2.end()); 
        return ct1 == ct2;
    }
};