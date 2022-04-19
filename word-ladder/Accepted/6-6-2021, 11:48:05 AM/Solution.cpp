// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dist; 
        for (string w : wordList) {
            dist[w] = -1; 
        }
        
        
        queue<string> q; 
        q.push(beginWord); 
        dist[beginWord] = 1; 
        
        while(!q.empty()) {
            string top = q.front(); q.pop(); 
            
            for (int i = 0; i < top.size(); ++i) {
                for (int j = 0; j < 26; ++j) {
                    char c = 'a' + j; 
                    string next = top;  
                    next[i] = c; 
                    if (dist.find(next) != dist.end() && dist[next] == -1) {
                        dist[next] = 1 + dist[top]; 
                        q.push(next); 
                        if (next == endWord) {
                            return dist[next]; 
                        }
                    }
                }
            }
        }
        return 0; 
        
        
    }
};