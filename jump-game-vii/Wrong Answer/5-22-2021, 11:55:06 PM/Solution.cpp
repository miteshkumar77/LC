// https://leetcode.com/problems/jump-game-vii

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int mincur = 0;
        int maxcur = 0;
        int minnex = 0;
        int maxnex = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (i > maxcur) {
                if (i > maxnex) break;
                maxcur = maxnex;
                mincur = minnex;
                i = mincur-1;
            } else {
                if (i == n - 1 && s[i] == '0') return true;
                if (s[i] == '0') {
                    maxnex = max(maxnex, i + maxJump);
                    minnex = min(minnex, i + minJump);
                }
            }
        }
        return false;

    }
};









