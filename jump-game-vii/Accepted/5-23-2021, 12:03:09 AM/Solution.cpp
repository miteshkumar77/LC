// https://leetcode.com/problems/jump-game-vii

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int mincur = INT_MAX;
        int maxcur = 0;
        int minnex = 0;
        int maxnex = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (i > maxcur) {
                if (i > maxnex) {
                    break;
                } else {
                    maxcur = maxnex;
                    mincur = minnex;
                    minnex = INT_MAX;
                    if (mincur >= n) return false;
                    i = mincur-1;
                }
            } else {
                if (s[i] == '0') {
                    if (i == n-1) return true;
                    maxnex = max(maxnex, i + maxJump);
                    minnex = min(minnex, i + minJump);
                    if (minnex >= n) return false;
                }
            }
        }
        return false;

    }
};









