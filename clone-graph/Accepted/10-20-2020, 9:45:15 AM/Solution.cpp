// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node; 
        }
        unordered_map<Node*, unordered_set<Node*>> graph; 
        unordered_set<Node*> visited; 
        queue<Node*> q; 
        graph[node] = unordered_set<Node*>(); 
        q.push(node); 
        while(!q.empty()) {
            Node* top = q.front(); q.pop(); 
            if (visited.find(top) == visited.end()) {
                visited.insert(top); 
                for (Node* n : top -> neighbors) {
                    graph[top].insert(n);
                    graph[n].insert(top); 
                    q.push(n); 
                }
            }
        }
        
        unordered_map<Node*, Node*> old2new; 
        for (auto p : graph) {
            old2new[p.first] = new Node(p.first -> val); 
        }
        
        Node* ret = old2new[node]; 
        
        for (auto p : graph) {
            for (auto q : p.second) {
                (old2new[p.first] -> neighbors).push_back(old2new[q]); 
            }
        }
        return ret; 
    }
};