// https://leetcode.com/problems/find-root-of-n-ary-tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_set<Node*> seen;
        for (auto node : tree) {
            for (auto child : node->children) {
                seen.insert(child);
            }
        }
        for (auto node : tree) {
            if (seen.find(node) == seen.end()) {
                return node;
            }
        }
        return nullptr;
        
    }
};