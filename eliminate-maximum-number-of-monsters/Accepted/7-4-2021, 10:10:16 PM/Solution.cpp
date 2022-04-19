// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> m(n);
        for (int i = 0; i < n; ++i) {
            m[i] = (dist[i] + speed[i] - 1)/speed[i];
        }
        sort(m.begin(), m.end());
        int p = 1;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            p += (m[i] - last - 1);
            last = m[i];
            if (p == 0) return i;
        }
        return n;
    }
};