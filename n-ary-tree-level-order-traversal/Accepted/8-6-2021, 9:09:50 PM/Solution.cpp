// https://leetcode.com/problems/n-ary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(Node* root) {
        queue<pair<Node*,int>> q;
        int lvl = -1;
        q.push({root, 0});
        vector<vector<int>> v;
        while(!q.empty()) {
            auto [n, d] = q.front();
            q.pop();
            if (!n) continue;
            if (d != lvl) {
                lvl = d;
                v.push_back({});
            }
            v.back().push_back(n->val);
            for (Node * neighbor : n->children) {
                q.push({neighbor, d+1});
            }
        }
        return v;
    }
};