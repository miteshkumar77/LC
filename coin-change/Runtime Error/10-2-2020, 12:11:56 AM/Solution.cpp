// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int> dp;
        int amt = 0;
        queue<pair<int,int>> q; 
        q.push(make_pair(0, 0));
        while(!q.empty()) {
            auto p = q.front(); 
            q.pop();
            if (p.first <= amount && dp.find(p.first) == dp.end()) {
                if (p.first == amount) {
                    return p.second;
                }
                dp.insert(p);
                for (int denom : coins) {
                    q.push(make_pair(p.first + denom, p.second + 1));
                }
            }
        }
        return -1;
    }
};