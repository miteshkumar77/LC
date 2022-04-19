// https://leetcode.com/problems/alien-dictionary

class Solution {
public:
    string alienOrder(vector<string>& words) {
        array<bool, 26> exists; 
        fill(exists.begin(), exists.end(), false); 
        array<unordered_set<char>, 26> graph; 
        fill(graph.begin(), graph.end(), unordered_set<char>()); 
        for (int i = 0; i < words.size(); ++i) {
            for (int k = 0; k < words[i].length(); ++k) {
                exists[words[i][k] - 'a'] = true; 
            }
            if (i != 0) {
                int t = 0; 
                int b = 0; 
                while(t < words[i - 1].length() && b < words[i].length()) {
                    if (words[i - 1][t] != words[i][b]) {
                        graph[words[i - 1][t] - 'a'].insert(words[i][b]); 
                        break; 
                    }
                    
                    
                    ++t; ++b; 
                    if (t < words[i - 1].length() && b >= words[i].length()) {
                        return ""; 
                    }
                }
            }
        }
        
        stack<char> topsort; 
        array<bool, 26> pre; 
        array<bool, 26> post; 
        fill(pre.begin(), pre.end(), false); 
        fill(post.begin(), post.end(), false); 
        bool busted = false; 
        function<void(char)> dfs = [&](char c) -> void {
            pre[c - 'a'] = true; 
            for (char x : graph[c - 'a']) {
                if (pre[x - 'a'] && !post[x - 'a']) {
                    busted = true; 
                    return; 
                }
                if (!pre[x - 'a']) {
                    dfs(x); 

                }
            }
            post[c - 'a'] = true; 
            cout << c << endl; 
            topsort.push(c); 
        };
        for (int i = 0; i < 26; ++i) {
            if (exists[i] && !post[i]) {
                dfs((char)(i + 'a'));
            }
        }
        
        if (busted) {
            return ""; 
        }
        string ans = ""; 
        while(!topsort.empty()) {
            ans+= topsort.top(); 
            topsort.pop(); 
        }
        return ans; 
    }
};