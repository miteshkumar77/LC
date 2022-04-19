// https://leetcode.com/problems/open-the-lock

class Solution {
public:
    array<int, 2> dirs{1, -1};
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> seen(deadends.begin(), deadends.end());
        if (seen.count("0000")) return -1;
        
        queue<pair<string,int>> q;
        q.push({"0000", 0}); 
        while(!q.empty()) {
            auto [ t,  dist] = q.front(); q.pop();
            
            for (int i = 0; i < 4; ++i) {
                for (int x = 0; x < 2; ++x) {
                    string tcpy = t;
                    tcpy[i] = (tcpy[i] - '0' + 10 + dirs[x]) % 10 + '0';
                    if (tcpy == target) return dist + 1;
                    if (seen.count(tcpy)) continue;
                    seen.insert(tcpy);
                    q.push({tcpy, dist + 1});
                }
            }
        }
        return -1;
    }
};