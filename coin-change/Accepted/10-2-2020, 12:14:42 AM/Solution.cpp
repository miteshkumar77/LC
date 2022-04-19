// https://leetcode.com/problems/coin-change

class Solution {
public:
    typedef unsigned long long int ulli;
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<unsigned long long int, unsigned long long int> dp;
        int amt = 0;
        queue<pair<unsigned long long int, unsigned long long int>> q; 
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
                    q.push(make_pair((ulli)p.first + denom, (ulli)p.second + 1));
                }
            }
        }
        return -1;
    }
};