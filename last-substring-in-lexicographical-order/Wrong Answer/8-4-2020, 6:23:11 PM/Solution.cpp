// https://leetcode.com/problems/last-substring-in-lexicographical-order

class Solution {
public:
    string lastSubstring(string s) {
        char maxascii = 0; 
        int largest_index = 0; 
        int i = 0; 
        for (char c : s) {
            if (maxascii < c) {
                maxascii = c; 
                largest_index = i;
            }
            ++i; 
        }
        
        return s.substr(largest_index, s.length() - largest_index); 
    }
};