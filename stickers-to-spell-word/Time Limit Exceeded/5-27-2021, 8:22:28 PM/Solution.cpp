// https://leetcode.com/problems/stickers-to-spell-word

class Solution {
public:
    
    int minStickers(vector<string>& stickers, string target) {
        set<vector<int>> seen;
        queue<pair<vector<int>, int>> q;
        vector<int> st(26, 0);
        for (char c : target) ++st[c-'a'];
        q.push({st, 0});
        vector<vector<int>> cts;
        for (const string& s : stickers) {
            cts.push_back(vector<int>(26, 0));
            for (char c : s) ++cts.back()[c-'a'];
        }
        vector<int> stp(26, 0);
        while(!q.empty()) {
            auto p = q.front();
            vector<int> t = p.first;
            int dist = p.second;
            q.pop();
            if (t == stp) return dist;
            if (seen.count(t)) continue;
            seen.insert(t);
            for (const auto& v : cts) {
                vector<int> next(t.begin(), t.end());
                for (int i = 0; i < 26; ++i) next[i] = max(0, t[i] - v[i]);
                q.push({next, dist + 1});
            }
        }
        return -1;
    }
};