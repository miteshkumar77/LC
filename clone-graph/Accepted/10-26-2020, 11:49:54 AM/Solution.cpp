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
        map<Node*, Node*> old2new;
        function<void(Node*, Node*)> dfs = [&](Node* parent, Node* cur) -> void {
            if (old2new.find(cur) == old2new.end()) {
                old2new[cur] = new Node(cur -> val);
                for (Node* neighbor : cur -> neighbors) {
                    dfs(cur, neighbor);
                }
            }
            if (parent)
                (old2new[parent] -> neighbors).push_back(old2new[cur]);
        };
        dfs(nullptr, node);
        return old2new[node];
    }
};