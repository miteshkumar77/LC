// https://leetcode.com/problems/escape-a-large-maze


class Solution {
public:
    int maxx = 1e6;
    set<array<int, 2>> mp;    
    int sz;
    array<int, 4> dx{0, 0, 1, -1};
    array<int, 4> dy{1, -1, 0, 0};
    array<int, 2> src;
    array<int, 2> dst;
    bool reachable = false;
    bool bfs(array<int, 2> p) {
        set<array<int, 2>> visited;
        queue<array<int, 2>> q;
        q.push(p);
        while(!q.empty() && visited.size() < sz) {
            auto t = q.front(); q.pop();
            if (t[0] < 0 || t[0] >= maxx || t[1] < 0 || t[1] >= maxx || mp.count(t) || visited.count(t)) continue;
            visited.insert(t);
            if (p[0] == src[0] && p[1] == src[1] && t[0] == dst[0] && t[1] == dst[1]) {
                reachable = true;
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                q.push({t[0] + dx[i], t[1] + dy[i]});
            }
        }
        cout << visited.size() << endl;
        return visited.size() >= sz;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        sz = 39800;
        for (const auto& p : blocked) {
            mp.insert({p[0], p[1]});
        }
        src = {source[0], source[1]};
        dst = {target[0], target[1]};
        auto rs = bfs(src);
        if (reachable) return true;
        auto rd = bfs(dst);
        return rs && rd;
        
        
    }
};