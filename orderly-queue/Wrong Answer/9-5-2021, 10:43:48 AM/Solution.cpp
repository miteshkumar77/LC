// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            int i = 0;
            int si = 0;
            string ans = s;
            int n = s.length();
            for (int j = 1; j < n; ++j) {
                if (ans[j] < ans[i]) {
                    si = j;
                    i = j;
                } else if (ans[j] == ans[i]) {
                    ++i;
                } else {
                    i = si;
                }
            }
            return ans.substr(si) + ans.substr(0, si);
        } else {
            sort(s.begin(), s.end()); return s;
        }
        
    }
};


















