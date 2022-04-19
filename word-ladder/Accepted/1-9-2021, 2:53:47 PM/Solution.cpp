// https://leetcode.com/problems/word-ladder

class Solution {
public:
    
    int bfsAction(unordered_map<string, vector<string>>& graph,
                  unordered_map<string, int>& dir_dist, 
                  unordered_map<string, int>& opp_dist,
                  queue<string>& dir_q) {
        
        string top = dir_q.front(); dir_q.pop();
        int W = top.length();
        int dist = dir_dist[top];
        for (int i = 0; i < W; ++i) {
            string wild = top.substr(0, i) + "*" + top.substr(i + 1, W); 
            for (string neighbor : graph[wild]) {
                if (dir_dist.find(neighbor) == dir_dist.end()) {
                    if (opp_dist.find(neighbor) != opp_dist.end()) {
                        return dist + opp_dist[neighbor] + 1;
                    }
                    dir_dist[neighbor] = dist + 1;
                    dir_q.push(neighbor);
                }
            }
        }
        return -1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;
        int W = beginWord.length();
        bool found_endWord = false;
        unordered_map<string, vector<string>> graph;
        for (string s : wordList) {
            if (s == endWord) found_endWord = true;
            
            for (int i = 0; i < W; ++i) {
                graph[s.substr(0, i) + "*" + s.substr(i + 1, W)].push_back(s);
            }
        }
        
        if (!found_endWord) return 0;
        
        unordered_map<string, int> fw_dist;
        unordered_map<string, int> bw_dist;
        fw_dist[beginWord] = 0;
        bw_dist[endWord] = 1;
        queue<string> fw_q;
        queue<string> bw_q;
        
        
        fw_q.push(beginWord); bw_q.push(endWord);
        while(!fw_q.empty() && !bw_q.empty()) {
            int fw_step = bfsAction(graph, fw_dist, bw_dist, fw_q); 
            if (fw_step != -1) {
                return fw_step;
            }
            int bw_step = bfsAction(graph, bw_dist, fw_dist, bw_q);
            if (bw_step != -1) {
                return bw_step;
            }
        }
        return 0;
    }
};