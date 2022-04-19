// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

class Solution {
public:
    
    bool isSubsequence(const string& s, const string& q) {
        int n = s.length();
        int m = q.length(); 
        int i = 0;
        int j = 0;
        while(i < n && j < m) {
            if (s[i] == q[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        return j == m;
    }
   
    string findLongestWord(string s, vector<string>& d) {
        int i = -1;
        int n = d.size(); 
        for (int x = 0; x < n; ++x) {
            bool b = (
                (i == -1 || (
                    (d[x].length() > d[i].length() || (d[x].length() == d[i].length() && d[x] < d[i])) 
                )) && isSubsequence(s, d[x])
            );
            if (b) {
                i = x;
            }
        }
        return i == -1?"": d[i];
    }
};