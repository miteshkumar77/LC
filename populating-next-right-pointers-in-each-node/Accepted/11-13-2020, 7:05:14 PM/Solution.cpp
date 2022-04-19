// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> bfsq;
        bfsq.push(make_pair(root, 0));
        int cd = -1;
        Node* cn = nullptr;
        while(!bfsq.empty()) {
            auto t = bfsq.front(); 
            bfsq.pop(); 
            if (!t.first) continue;
            bfsq.push(make_pair(t.first -> left, t.second + 1));
            bfsq.push(make_pair(t.first -> right, t.second + 1)); 
            if (t.second == cd) {
                cn -> next = t.first;
            } else {
                cd = t.second;
            }
            cn = t.first;
        }
        return root;
    }
};