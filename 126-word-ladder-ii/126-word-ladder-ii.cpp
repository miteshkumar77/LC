class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> successor;
        unordered_set<string> visited;
        unordered_map<int, vector<string>> dist;
        for (string const& s : wordList) {
            for (int i = 0; i < s.length(); ++i) {
                successor[s.substr(0, i) + "*" + s.substr(i+1)].push_back(s);
            }
        }
        /*
        for (auto p : successor) {
            cout << p.first << " : ";
            for (string const& w : p.second) {
                cout << w << " ";
            }
            cout << endl;
        }*/
        
        
        
        queue<pair<int, string>> q;
        q.push({0, beginWord});
        int fdist = -1;
        while(!q.empty()) {
            auto [dst, wrd] = q.front(); q.pop();
            if (!visited.count(wrd)) {
                // cout << wrd << endl;
                visited.insert(wrd);
                dist[dst].push_back(wrd);
                if (wrd == endWord) {
                    fdist = dst;
                }
                for (int i = 0; i < wrd.length(); ++i) {
                    string tmp = wrd.substr(0, i) + "*" + wrd.substr(i+1);
                    if (successor.count(tmp)) {
                        for (string const& neighbor : successor[tmp]) {
                            q.push({dst + 1, neighbor});
                        }
                    }
                }
            }
        }
        if (fdist == -1) return {};
        
        vector<vector<string>> ans;
        vector<string> path;
        function <void(string const&, int)> bt = [&](string const& wrd, int dst) {
            path.push_back(wrd);
            if (dst == 0) {
                reverse(path.begin(), path.end());
                ans.push_back(path);
                reverse(path.begin(), path.end());
            } else {
                for (string const& s : dist[dst-1]) {
                    int diffs = 0;
                    for (int i = 0; i < s.length(); ++i) {
                        diffs += (s[i] != wrd[i]);
                    }
                    if (diffs == 1) {
                        bt(s, dst-1);
                    }
                }
            }
            path.pop_back();
        };
        bt(endWord, fdist);
        return ans;
    }
    
};