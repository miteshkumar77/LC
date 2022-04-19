// https://leetcode.com/problems/find-players-with-zero-or-one-losses

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> players;
        unordered_map<int,int> losses;
        for (auto const& v : matches) {
            players.insert(v[0]);
            players.insert(v[1]);
            ++losses[v[1]];
        }
        vector<vector<int>> ans{{}, {}};
        for (int i : players) {
            if (!losses.count(i)) {
                ans[0].push_back(i);
            } else if (losses[i] == 1) {
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};