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
        for (int i = 1; i < n; ++i) {
            if (m[i] == m[i-1]) {
                return i;
            }
        }
        return n;
    }
};