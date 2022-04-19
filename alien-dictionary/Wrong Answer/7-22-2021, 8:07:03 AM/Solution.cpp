// https://leetcode.com/problems/alien-dictionary

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<int>> graph(26, vector<int>());
        vector<bool> in(26, false);
        bool ok;
        for (int w = 0; w+1 < words.size(); ++w) {
            ok = true;
            for (int i = 0; i < min(words[w].length(), words[w+1].length()); ++i) {
                if (ok && words[w][i] != words[w+1][i]) {
                    ok = false;
                    graph[words[w+1][i]-'a'].push_back(words[w][i]-'a');
                }
                in[words[w+1][i]-'a'] = true;
                in[words[w][i]-'a'] = true;
            }
        }
        string ans;
        vector<bool> pre(26, false);
        vector<bool> post(26, false);
        function<bool(int)> ts = [&](int node) -> bool {
            if (post[node]) return true;
            if (pre[node]) return false;
            pre[node] = true;
            for (int n : graph[node]) {
                if (!ts(n)) return false;
            }
            ans.push_back((char)(node+'a'));
            post[node] = true;
            return true;
        };
        for (int i = 0; i < 26; ++i) {
            if (!in[i]) continue;
            if (!ts(i)) return "";
        }
        return ans;
    }
};