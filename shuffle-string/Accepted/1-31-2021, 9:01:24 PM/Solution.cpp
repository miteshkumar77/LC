// https://leetcode.com/problems/shuffle-string

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.length(); 
        for (int i = 0; i < n; ++i) {
            while(indices[i] != i && indices[indices[i]] != indices[i]) {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }
        return s;
    }
};