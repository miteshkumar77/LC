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
        if (!node) return node;
        unordered_map<Node*, Node*> seen;
        function<void(Node*, Node*)> dfs = [&](Node* parent, Node* cur) -> void {
            
            if (seen.find(cur) == seen.end()) {
                seen[cur] = new Node(cur -> val);
                for (Node* neighbor : cur -> neighbors) {
                    dfs(cur, neighbor);
                }
            }
            if (parent)
                (seen[parent] -> neighbors).push_back(seen[cur]);

//             if (seen.find(cur) != seen.end()) {
//                 (seen[parent] -> neighbors).push_back(seen[cur]);
//             } else {
                    
//                 seen[cur] = new Node(cur -> val);
                
//                 if (parent)
//                     (seen[parent] -> neighbors).push_back(seen[cur]);
                
//                 for (Node* neighbor : cur -> neighbors) {
//                     dfs(cur, neighbor);
//                 }
//             }
        };
        dfs(nullptr, node);
        return seen[node];
    }
};