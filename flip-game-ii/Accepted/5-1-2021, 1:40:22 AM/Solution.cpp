// https://leetcode.com/problems/flip-game-ii

class Solution {
public:
    bool canWin(string currentState) {
        unordered_map<string, bool> wins;
        return dfs(wins, currentState);
    }
    
    bool dfs(unordered_map<string, bool>& wins, string& state) {
        if (wins.count(state)) {
            return wins[state];
        }
        int n = state.length();
        for (int i = 0; i + 1 < n; ++i) {
            if (state[i] == state[i + 1] && state[i] == '+') {
                state[i] = '-';
                state[i + 1] = '-';
                if (!dfs(wins, state)) {
                    state[i] = '+';
                    state[i + 1] = '+';
                    wins[state] = true;
                    return true;
                }
                state[i] = '+';
                state[i + 1] = '+';
            }
        }
        wins[state] = false;
        return false;
    }
};