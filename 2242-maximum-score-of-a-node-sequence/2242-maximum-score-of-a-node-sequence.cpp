class Solution {
public:
    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<array<int, 2>>> best3(n);
        vector<vector<int>> graph(n);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                best3[i].push_back({scores[j], j});
                sort(best3[i].begin(), best3[i].end());
                if (best3[i].size() > 3)
                    best3[i].erase(best3[i].begin());
            }
        }
        long long ans{LLONG_MIN};
        for (auto e : edges) {
            int tmp{scores[e[0]] + scores[e[1]]};
            for (auto i : best3[e[0]]) {
                for (auto j : best3[e[1]]) {
                    if (i[1] != e[1] && i[1] != j[1] && j[1] != e[0]) {
                        ans = max(ans, (long long)(tmp + i[0] + j[0]));
                    }
                }
            }
        }
        return ans == LLONG_MIN ? -1 : ans;
    }
};