// https://leetcode.com/problems/word-ladder

class Solution {
public:
    typedef pair<string, int> psi; 
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, unordered_set<string> > graph; 
        unordered_map<string, list<string> > rgraph; 
        unordered_set<string> visited; 
        
        // Preprocess
        wordList.push_back(beginWord); 
        for (string s : wordList) {
            // cout << s << ": "; 
            for (int i = 0; i < s.length(); ++i) {
                
                string q = s; 
                q[i] = '*'; 
                // cout << q << ' '; 
                rgraph[q].push_back(s); 
            } 
        } 
        // cout << endl; 
        // Construct graph
        for (auto collection : rgraph) {
            for (auto it1 = collection.second.begin(); 
                 it1 != collection.second.end(); ++it1) {
                string s1 = *it1; 
                for (auto it2 = next(it1); 
                    it2 != collection.second.end(); ++it2) {
                    string s2 = *it2; 
                    // cout << s1 << ' ' << s2 << endl; 
                    graph[s1].insert(s2); 
                    graph[s2].insert(s1); 
                } 
            }
        }
        
        
//         for (auto collection : graph) {
//             cout << collection.first << ": "; 
//             for (string s : collection.second) {
                // cout << s << ' '; 
//             }cout << endl; 
//         }
        
        
        queue<psi> q; 
        q.push(psi(beginWord, 1));
        visited.insert(beginWord); 
        while(!q.empty()) {
            psi top = q.front(); q.pop(); 
            // cout << top.first << ' ' << top.second << endl; 

            for (string w : graph[top.first]) {
                if (visited.find(w) == visited.end()) {
                    if (w == endWord) {
                        return top.second + 1; 
                    }
                    q.push(psi(w, top.second + 1));
                    visited.insert(w); 
                }
            }
        }
        return 0; 
        
    }
};