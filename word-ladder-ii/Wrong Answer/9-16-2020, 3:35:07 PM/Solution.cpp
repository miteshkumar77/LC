// https://leetcode.com/problems/word-ladder-ii

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord); 
        unordered_map<string, vector<string>> pools; 
        for (string word : wordList) {
            string s = word; 
            for (int i = 0; i < word.length(); ++i) {
                s[i] = '*'; 
                pools[s].push_back(word); 
                s[i] = word[i]; 
            }
        }
        
        
        unordered_map<string, vector<string>> graph; 
        unordered_map<string, int> dist; 
        
        for (auto p : pools) {
            for (int i = 0; i < p.second.size(); ++i) {
                for (int j = i + 1; j < p.second.size(); ++j) {
                    graph[p.second[i]].push_back(p.second[j]); 
                    graph[p.second[j]].push_back(p.second[i]); 
                    
                }
            }
        }
        
        for (string s : wordList) {
            dist[s] = INT_MAX; 
        }
        
        queue<pair<string, int>> q; 
        q.push(make_pair(endWord, 0)); 
        
        while(!q.empty()) {
            string word = q.front().first; 
            int cdist = q.front().second; 
            q.pop(); 
            if (cdist < dist[word]) {
                dist[word] = cdist; 
                if (word == beginWord) {
                    break; 
                }
                for (string neighbor : graph[word]) {
                    q.push(make_pair(neighbor, cdist + 1)); 
                }
            }
        }
        
        // for (auto p : dist) {
        //     cout << p.first << ' ' << p.second << endl; 
        // }
        
        if (dist[beginWord] == INT_MAX) {
            return vector<vector<string>>(); 
        }
        
        vector<vector<string>> ans; 
        vector<string> box; 
        function<void(string&)> bt = [&](string& node) -> void {
            box.push_back(node); 
            if (node == endWord) {
                ans.push_back(box); 
                box.pop_back(); 
                return; 
            }    
            
            int mindist = INT_MAX; 
            for (string neighbor : graph[node]) {
                mindist = min(mindist, dist[neighbor]); 
            }
            
            if (mindist == INT_MAX) {
                box.pop_back(); 
                return;
            }
            for (string neighbor : graph[node]) {
                if (dist[neighbor] == mindist) {
                    bt(neighbor); 
                }
            }
            
            box.pop_back(); 
        };
            
        bt(beginWord); 
        return ans; 
        
    }
};