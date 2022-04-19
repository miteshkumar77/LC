// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    bool bt(int m, vector<int>& matchsticks, array<int, 4>& squares, int sum) {
        if (m == matchsticks.size()) {
            return squares[0] + squares[1] + squares[2] + squares[3] == 4 * sum;
        }
        for (int i = 0; i < 4; ++i) {
            if (squares[i] + matchsticks[m] <= sum) {
                squares[i] += matchsticks[m];
                bool ret = bt(m + 1, matchsticks, squares, sum);
                squares[i] -= matchsticks[m];
                if (ret) return true;
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        array<int, 4> squares{0,0,0,0};
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        return bt(0, matchsticks, squares, total/4);
    }
};