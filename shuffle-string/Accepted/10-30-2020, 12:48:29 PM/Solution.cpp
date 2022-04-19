// https://leetcode.com/problems/shuffle-string

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for (int i = 0; i < s.length(); ++i) {
            while(indices[i] != i && indices[indices[i]] != indices[i]) {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]); 
            } 
        }
        return s;
    }
};