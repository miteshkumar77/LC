// https://leetcode.com/problems/word-ladder

class Solution {
public:
    
    int handle_iter(unordered_map<string, int>& dist, unordered_map<string, int>& r_dist, queue<pair<string,int>>& q, unordered_map<string, vector<string>>& graph) {
        auto [w, d] = q.front(); q.pop();
        // cout << w << ' ' << d << ' ' << dist["NAME"] << endl;
        if (dist.count(w) && dist[w] == -1) {
            dist[w] = d;
            if (r_dist.count(w) && r_dist[w] != -1) {
                return d + r_dist[w] + 1;
            }
            for (int i = 0; i < w.length(); ++i) {
                string tmp = w.substr(0, i) + "*" + w.substr(i+1);
                if (!graph.count(tmp)) continue;
                for (string const& neighbor : graph[tmp]) {
                    q.push({neighbor, d+1});
                }
                graph.erase(tmp);
            }
        }
        return -1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, int> f_dist;
        unordered_map<string, int> b_dist;
        f_dist["NAME"] = 1;
        b_dist["NAME"] = -1;
        unordered_map<string, vector<string>> graph;
        
        for (string const& w : unordered_set<string>(wordList.begin(), wordList.end())) {
            f_dist[w] = -1;
            b_dist[w] = -1;
            for (int i = 0; i < w.length(); ++i) {
                string tmp = w.substr(0, i) + "*" + w.substr(i+1);
                // cout << w << ' ' << tmp << endl;
                graph[tmp].push_back(w);
            }
        }
        // if (!b_dist.count(endWord)) return 0;
        
        queue<pair<string, int>> f_q;
        queue<pair<string, int>> b_q;
        f_q.push({beginWord, 0});
        b_q.push({endWord, 0});
        while(!f_q.empty() || !b_q.empty()) {
            if (!f_q.empty()) {
                int flag = handle_iter(f_dist, b_dist, f_q, graph);
                if (flag != -1) return flag;
            }
            if (!b_q.empty()) {
                int flag = handle_iter(b_dist, f_dist, b_q, graph);
                if (flag != -1) return flag;
            }
        }
        return 0;
    }
};