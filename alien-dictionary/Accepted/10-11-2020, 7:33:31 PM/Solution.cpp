// https://leetcode.com/problems/alien-dictionary

class Solution {
public:
    
    
    bool topsort(string& stack, unordered_set<char>& pre, unordered_set<char>& post, 
                 unordered_map<char, unordered_set<char>>& graph, char node) {
        
        if (pre.find(node) != pre.end()) {
            if (post.find(node) == post.end()) {
                return false;
            }
            return true;
        }
        
        pre.insert(node);
        
        for (char c : graph[node]) {
            if (!topsort(stack, pre, post, graph, c)) {
                return false;
            }
        }
        post.insert(node);
        stack += node;
        return true;
    }
    
    string alienOrder(vector<string>& words) {
        
        unordered_map<char, unordered_set<char>> graph;
        
        int n = words.size();
        for (int i = 0; i < n - 1; ++i) {
            
            string w1 = words[i];
            string w2 = words[i + 1];
            for (char c : w1) {
                graph.insert(make_pair(c, unordered_set<char>()));
            }
            bool diff = false;
            int size = min(w1.size(), w2.size());
            for (int i = 0; i < size; ++i) {
                if (w1[i] != w2[i]) {
                    graph[w1[i]].insert(w2[i]);
                    diff = true;
                    break;
                }
            }
            
            if (!diff) {
                if (w1.size() > w2.size()) {
                    return "";
                }
            }
        }
        for (char c : words.back()) {
            graph.insert(make_pair(c, unordered_set<char>()));
        }
        
        unordered_set<char> pre; unordered_set<char> post; string ans;
        
        for (auto p : graph) {
            if (!topsort(ans, pre, post, graph, p.first)) {
                return "";
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        

        
    }
};