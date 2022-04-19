// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        array<int, 3> r{0, 0, 0};
        array<int, 3> c{0, 0, 0};
        int d1 = 0;
        int d2 = 0;
        
        int sgn = 1;
        for (auto const& m : moves) {
            r[m[0]] += sgn;
            c[m[1]] += sgn;
            if (m[0] == m[1]) {
                d1 += sgn;
            }
            if (2 - m[1] == m[0]) {
                d2 += sgn;
            }
            if (abs(r[m[0]]) == 3 || abs(c[m[1]]) == 3 || abs(d1) == 3 || abs(d2) == 3) {
                return sgn == 1 ? "A" : "B";
            }
            sgn *= -1;
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};