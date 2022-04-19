// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusted(N+1, 0);
        vector<int> trusts(N+1, 0);
        for (auto const& p : trust) {
            ++trusted[p[1]];
            ++trusts[p[0]];
        }
        int ans = -1;
        bool found = false;
        for (int i = 1; i <= N; ++i) {
            if (trusts[i] == 0 && trusted[i]+1 == N) {
                if (found) return -1;
                ans = i;
                found = true;
            }
        }
        return ans;
    }
};