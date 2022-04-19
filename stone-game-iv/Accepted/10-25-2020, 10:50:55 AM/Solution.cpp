// https://leetcode.com/problems/stone-game-iv

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, 0);
        // 0 -> not calculated yet
        // 1 -> current player wins
        // -1 -> current player loses
        
        function<bool(int)> wins = [&](int n) -> bool {
            if (n == 0) return false;
            if (dp[n] != 0) return dp[n] == 1;
            for (int i = 1; i * i <= n; ++i) {
                if (!wins(n - i * i)) {
                    dp[n] = 1;
                    return true;
                }
            }
            dp[n] = -1;
            return false;
        };
        
        return wins(n);
    }
};