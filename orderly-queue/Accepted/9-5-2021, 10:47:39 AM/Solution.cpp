// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            int i = 0;
            int si = 0;
            string ans = s;
            int n = s.length();
            for (int i = 0; i < n; ++i) {
                ans = min(ans, s.substr(i) + s.substr(0, i));
            }
            return ans;
        } else {
            sort(s.begin(), s.end()); return s;
        }
        
    }
};


















