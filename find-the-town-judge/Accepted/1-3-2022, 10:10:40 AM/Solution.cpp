// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusted(N+1, 0);
        for (auto const& p : trust) {
            trusted[p[0]] = -1;
        }
        for (auto const& p : trust) {
            if (trusted[p[1]] != -1) {
                ++trusted[p[1]];
            }
        }
        int ans = -1;
        bool found = false;
        for (int i = 1; i <= N; ++i) {
            if (trusted[i]+1 == N) {
                if (found) return -1;
                ans = i;
                found = true;
            }
        }
        return ans;
    }
};